#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<queue>
#include<fstream>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
using namespace std;

using ll = long long;
using ull = unsigned long long;
int MX = 101;
const ll WER = 1e9 + 2;
bool check(vector <ll> & bpb, int x, int y)
{
	if (x == y)
		return true;
	if (x > y)
		return check(bpb, y, x);
	return binary_search(bpb.begin(), bpb.end(), WER*x+y);
}

long long getans(vector<int>& v1, vector<int>& v2, vector<ll>&bpb)
{
	//cout << "HER " << endl;
	//for (auto a : v1)
	//	cout << a << ' ';
//	cout << endl;
	//for (auto b : v2)
	//	cout << b << endl;
	//cout << endl;
	priority_queue<pair<int, int>>pq;
	// ,   
	vector<int>cands(v1.size(), 0);
	for (int i = 0; i < v1.size(); i++)
	{
		pq.push({ v1[i] + v2[0], i });
	}
	while (!pq.empty())
	{
		auto pr = pq.top();
		int x = pr.second, y = cands[pr.second];
		//cout << "adad " << v1[x] << ' ' << v2[y] << ' ' << badpairs.count({v2[y],v1[x]})<< endl;
		if (!check(bpb, v1[x], v2[y]))
		{
			//	cout << "WIN " << x << ' ' << y << endl;
			return v1[x] + v2[y];
		}
		else
		{
			pq.pop();
			if (y != v2.size() - 1)
			{
				cands[x]++;
				pq.push({ v1[x] + v2[cands[x]],x });
			}
		}
	}
	return 0;
}

void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n, m;
		cin >> n >> m;
		vector<int>q;
	//	map<int, int>nums;
	//	set<pair<int, int>>badpairs;
		vector<ll>bpb;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			q.push_back(x);
		//	nums[x]++;
		}
		//x<y
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			bpb.push_back(WER*x+y);
			//badpairs.insert({ x,y });
		}
		sort(q.begin(), q.end());
		sort(bpb.begin(), bpb.end());
		//cout << badpairs.count({ 6,7 }) << endl;
		vector<vector<int>>numbs(n + 1);
	/*	for (auto a : nums)
		{
			numbs[a.second].push_back(a.first);
		}*/
		int curr = 0;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && q[i] != q[i - 1])
			{
				numbs[curr].push_back(q[i - 1]);
			//	cout << q[i - 1] << ' ' << curr << endl;
				curr = 1;
			}
			else
				curr++;
		}
		numbs[curr].push_back(q[n - 1]);
		vector<int> nonzero;
		for (int i = 1; i <= n; i++)
		{
			if (numbs[i].size() > 0)
			{
				nonzero.push_back(i);
				sort(numbs[i].begin(), numbs[i].end());
				reverse(numbs[i].begin(), numbs[i].end());
			}
		}
		long long ans = 0;
		for (int i = 0; i < nonzero.size(); i++)
		{
			for (int j = i; j < nonzero.size(); j++)
			{
				ans = max(ans, getans(numbs[nonzero[i]], numbs[nonzero[j]], bpb) * 1LL * (nonzero[i] + nonzero[j]));
			}
		}
		cout << ans << endl;
	}
}


int main()
{
	solve();
}