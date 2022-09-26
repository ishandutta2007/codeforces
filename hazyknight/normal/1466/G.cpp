#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;
const ll MOD = 1000000007;

int n,q,N;
int nxt[MAXN];

char s[MAXN];
char t[MAXN];
char S[MAXN];

bool vis[MAXN];

ll ans;
ll pw[MAXN];
ll inv[MAXN];
ll sum[MAXN][26];

unordered_map<int,ll> mem[26][21];

void getnxt()
{
	nxt[1] = 0;
	for (int i = 1,j = 0;i < N;i++)
	{
		while (j && s[i] != s[j])
			j = nxt[j];
		if (s[i] == s[j])
			j++;
		nxt[i + 1] = j;
	}
}

ll solve(int lim,int st,vector<char> a)
{
	if (!a.size())
		return pw[lim - st + 1];
	if (lim < st)
		return 0;
	if (a.size() == 1)
		return (sum[lim][a[0] - 'a'] - sum[st - 1][a[0] - 'a']) * inv[n - lim] % MOD;
	bool same = 1;
	for (int i = 1;i < a.size();i++)
		same &= (a[i] == a[0]);
	if (same && mem[a[0] - 'a'][st].find(a.size()) != mem[a[0] - 'a'][st].end())
		return mem[a[0] - 'a'][st][a.size()];
	ll res = 0;
	vector<char> odd,even;
	for (int i = 0;i < a.size();i++)
		if (i & 1)
			odd.push_back(a[i]);
		else
			even.push_back(a[i]);
	bool ok = 1;
	for (int i = 0;i < odd.size();i++)
		if (odd[i] != t[st])
			ok = 0;
	if (ok)
		(res += solve(lim,st + 1,even)) %= MOD;
	ok = 1;
	for (int i = 0;i < even.size();i++)
		if (even[i] != t[st])
			ok = 0;
	if (ok)
		(res += solve(lim,st + 1,odd)) %= MOD;
	if (same)
		mem[a[0] - 'a'][st][a.size()] = res;
	return res;
}

int main()
{
	scanf("%d%d%s%s",&n,&q,s,t + 1);
	pw[0] = 1;
	inv[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		pw[i] = pw[i - 1] * 2 % MOD;
		inv[i] = inv[i - 1] * ((MOD + 1) / 2) % MOD;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < 26;j++)
			sum[i][j] = sum[i - 1][j];
		(sum[i][t[i] - 'a'] += pw[n - i]) %= MOD;
	}
	N = strlen(s);
	getnxt();
	while (q--)
	{
		int lim = 0;
		scanf("%d%s",&lim,S);
		for (int i = 0;i < 26;i++)
			for (int j = 1;j <= 20;j++)
				mem[i][j].clear();
		int l = strlen(S);
		for (int i = 0,j = 0;i < l;i++)
		{
			vis[i] = 0;
			while (j && S[i] != s[j])
				j = nxt[j];
			if (S[i] == s[j])
				j++;
			if (j == N)
			{
				vis[i] = 1;
				j = nxt[j];
			}
		}
		ans = 0;
		for (int j = 0;j <= N;j++)
		{
			vector<char> a;
			bool ok = 1;
			for (int k = 0;k < j && k < l;k++)
				if (S[k] != s[N - j + k])
					ok = 0;
			int k = j - 1 + N + 1;
			for (;k < l;k += N + 1)
			{
				a.push_back(S[k - N]);
				if (!vis[k])
					ok = 0;
			}
			k -= N + 1;
			if (k + 1 < l)
				a.push_back(S[k + 1]);
			for (int K = k + 2;K < l;K++)
				if (S[K] != s[K - k - 2])
					ok = 0;
			if (ok)
				(ans += solve(lim,1,a)) %= MOD;
		}
		printf("%lld\n",(ans + MOD) % MOD);
	}
	return 0;
}