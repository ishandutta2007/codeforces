//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int maxn = 2000111;
const int mod = 1e9+9;
const int base = 233333;
struct SAM
{
	int go[maxn][26], pre[maxn], len[maxn], tot;
	void init()
	{
		tot = 1;
	}
	int append(int p, int c)
	{
		int np = ++tot;
		len[np] = len[p]+1;
		while (p && !go[p][c]) go[p][c] = np, p = pre[p];
		if (!p)
		{
			pre[np] = 1;
			return np;
		}
		int q = go[p][c];
		if (len[q] == len[p]+1) pre[np] = q;
		else
		{
			int nq = ++tot;
			len[nq] = len[p]+1;
			pre[nq] = pre[q];
			pre[np] = pre[q] = nq;
			for (int i=0; i<26; i++) go[nq][i] = go[q][i];
			while (p && go[p][c]==q) go[p][c] = nq, p = pre[p];
		}
		return np;
	}
	vector<int> con[maxn];
	int cnt[maxn];
	void dfs(int x)
	{
		for (int i=0; i<con[x].size(); i++)
		{
			int u = con[x][i];
			dfs(u);
			cnt[x] += cnt[u]; 
		}
	}
	void prepare()
	{
		for (int i=2; i<=tot; i++) con[pre[i]].PB(i);
		dfs(1);
	}
	int pgo(int p, int c)
	{
		while (p>1&&!go[p][c]) p = pre[p];
		return !go[p][c]? 1: go[p][c];
	}
	int query(char s[], int n)
	{
		int l = 0;
		int p = 1;
		int hs = 0, pw = 1;
		for (int i=1; i<=n; i++)
		{
			int c = s[i]-'a';
			while (p>1&&!go[p][c]) p = pre[p];
			l = min(l, len[p])+(go[p][c]>0);
			p = max(1, go[p][c]);
			hs = (1ll*hs*base+s[i])%mod;
			pw = 1ll*pw*base%mod;
		}
		int all_hs = hs;
		int ret = 0;
		for (int i=1; i<=n; i++)
		{
			int c = s[i]-'a';
			while (p>1&&len[pre[p]]>=n) p = pre[p];
			l = min(l, len[p]);
			if (l>=n) ret += cnt[p];
			while (p>1&&!go[p][c]) p = pre[p];
			l = min(l, len[p])+(go[p][c]>0);
			p = max(1, go[p][c]);
			hs = ((1ll*hs*base+s[i]-1ll*s[i]*pw)%mod+mod)%mod;
			if (hs==all_hs) break;
		}
		return ret;
	}
}sam;
char s[maxn];
int main()
{
	sam.init();
	scanf("%s", s+1);
	int n = strlen(s+1);
	int p = 1;
	for (int i=1; i<=n; i++)
	{
		p = sam.append(p, s[i]-'a');
	}
	p = 1;
	for (int i=1; i<=n; i++)
	{
		p = sam.go[p][s[i]-'a'];
		sam.cnt[p]++;
	}
	sam.prepare();
	int q;
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%s", s+1);
		int l = strlen(s+1);
		printf("%d\n", sam.query(s, l));
	}
    return 0;
}