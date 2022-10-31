#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
//p^{-1}q
long long calc(int p, int num, vector<vector<int>>& childs, map<pair<int, int>, long long>& dp, vector<long long>& s)
{
	if (dp.count({ p,num }))
		return dp[{p, num}];
	long long ans = num * s[p];
	if (childs[p].size() == 0)
		return ans;
	int mn = num / childs[p].size(), mx = mn + 1, numb = num % childs[p].size();
	vector<long long>pt;
	pt.reserve(childs[p].size());
	for (auto a : childs[p])
	{
		long long v1 = calc(a, mn, childs, dp, s);
		long long v2 = 0;
		if(numb>0)
			v2 = calc(a, mx, childs, dp, s);
		ans += v1;
		pt.push_back(v2 - v1);
	}
	sort(pt.begin(), pt.end());
	reverse(pt.begin(), pt.end());
	for (int i = 0; i < numb; i++)
		ans += pt[i];
//	cout << p << ' ' << num << ' ' << ans << endl;
	dp[{p, num}] = ans;
	return ans;
}
int main()
{
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int n, k;
		cin >> n>>k;
		vector<int>p(n);
		vector<vector<int>>childs(n);
		vector<int>anses(n + 1);
		for (int i = 1; i < n; i++)
		{
			cin >> p[i];
			p[i]--;
			childs[p[i]].push_back(i);
		}
		vector<long long>s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		map<pair<int,int>, long long>dp;
		cout << calc(0,k,childs,dp,s)<<endl;
	}
}