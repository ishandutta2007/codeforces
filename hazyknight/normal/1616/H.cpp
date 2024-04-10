#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 150005;
const ll MOD = 998244353;

int n,x;
int a[MAXN];

ll ans;
ll pw[MAXN];

map<int,vector<int> > v;

ll solve(int h,vector<int> &a0,vector<int> &a1)
{
	if (!a0.size() || !a1.size())
		return 0;
	if (h < 0)
		return (pw[a0.size()] - 1) * (pw[a1.size()] - 1) % MOD;
	/*
	cout << h << ": " << endl;
	for (int i = 0;i < a0.size();i++)
		cout << a[a0[i]] << ' ';
	cout << endl;
	for (int i = 0;i < a1.size();i++)
		cout << a[a1[i]] << ' ';
	cout << endl;
	cout << "----------" << endl;
	*/
	vector<int> a00,a01,a10,a11;
	int st = (1 << h);
	for (int i = 0;i < a0.size();i++)
		if (a[a0[i]] & st)
			a01.push_back(a0[i]);
		else
			a00.push_back(a0[i]);
	for (int i = 0;i < a1.size();i++)
		if (a[a1[i]] & st)
			a11.push_back(a1[i]);
		else
			a10.push_back(a1[i]);
	if (x >> h & 1)
	{
		ll r1 = solve(h - 1,a00,a11),r2 = solve(h - 1,a10,a01);
	//	cerr << "ret=" << ((r1 + pw[a00.size()] + pw[a11.size()] + 1) * (r2 + pw[a10.size()] + pw[a01.size()] + 1) - pw[a0.size()] - pw[a1.size()] + 1) % MOD << endl;
		return ((r1 + pw[a00.size()] + pw[a11.size()] - 1) * (r2 + pw[a10.size()] + pw[a01.size()] - 1) - pw[a0.size()] - pw[a1.size()] + 1) % MOD;
	}
	ll r1 = solve(h - 1,a00,a10),r2 = solve(h - 1,a01,a11);
//	cerr << "ret2=" << (r1 + r2) % MOD << endl;
	return (r1 + r2) % MOD;
}

int main()
{
	scanf("%d%d",&n,&x);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	pw[0] = 1;
	for (int i = 1;i <= n;i++)
		pw[i] = pw[i - 1] * 2 % MOD;
	int st = 0,h = 0;
	for (int i = 29;i >= 0;i--)
		if (x >> i & 1)
		{
			h = i;
			st = 1 << i;
			break;
		}
	if (!st)
	{
		for (int i = 1;i <= n;i++)
			v[a[i]].push_back(i);
		for (map<int,vector<int> >::iterator it = v.begin();it != v.end();it++)
			(ans += pw[it->second.size()] - 1) %= MOD;
		printf("%lld\n",ans);
		return 0;
	}
	for (int i = 1;i <= n;i++)
		v[a[i] & ~(st - 1)].push_back(i);
	for (map<int,vector<int> >::iterator it = v.begin();it != v.end();it++)
		if (it->second.size())
		{
			if (it->first & st)
				(ans += solve(h - 1,v[it->first ^ st],it->second)) %= MOD;
			else
				(ans += solve(h - 1,it->second,v[it->first ^ st])) %= MOD;
		//	cerr << ans << endl;
			(ans += pw[v[it->first ^ st].size()] + pw[it->second.size()] - 2) %= MOD;
		//	cerr << ans << endl;
			it->second.clear();
			v[it->first ^ st].clear();
		}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}