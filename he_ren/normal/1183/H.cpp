#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

char s[MAXN];
int nxt[MAXN][26];

ll f[MAXN][MAXN];
inline void chk_add(ll &a,ll b){ a = min(a + b, linf);}

int main(void)
{
	int n;
	ll d;
	scanf("%d%lld%s",&n,&d,s+1);
	
	for(int i=0; i<26; ++i) nxt[n+1][i] = n+1;
	for(int i=n; i>=1; --i)
	{
		memcpy(nxt[i], nxt[i+1], sizeof(nxt[i]));
		nxt[i][s[i] - 'a'] = i;
	}
	
	f[n+1][0] = 1;
	for(int i=0; i<26; ++i)
		if(nxt[1][i] <= n)
			f[nxt[1][i]][1] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=i; ++j) if(f[i][j])
		{
			for(int k=0; k<26; ++k)
			{
				int t = nxt[i+1][k];
				if(t > n) continue;
				chk_add(f[t][j+1], f[i][j]);
			}
			chk_add(f[n+1][j], f[i][j]);
		}
	
	ll res = d * n;
	for(int i=n; i>=0 && d; --i)
	{
		ll cur = min(d, f[n+1][i]);
		d -= cur;
		res -= cur * i;
	}
	
	if(d) printf("-1");
	else printf("%lld",res);
	return 0;
}