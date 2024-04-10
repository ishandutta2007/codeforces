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
		int n;
		cin >> n;
		if (n > 3)
		{
			long long ans = 0, allones = 1;
			for (int i = 0; i < n; i++)
			{
				int x;
				cin >> x;
				if (i != 0 && i != n - 1)
				{
					if (x != 1)
						allones = 0;
					ans += (x + 1) / 2;
				}
			}
			if (allones)
				cout << -1 << '\n';
			else
				cout << ans << '\n';
		}
		else
		{
			int a, b, c;
			cin >> a >> b >>c;
			if (b % 2 == 0)
				cout << b / 2 << '\n';
			else
				cout << -1 << '\n';
		}
	}
}


int main()
{
	solve();
}