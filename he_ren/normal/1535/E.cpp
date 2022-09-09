#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXQ = 3e5 + 5;
const int LB = 19 + 2;

int lb[MAXQ];

int dep[MAXQ], anc[MAXQ][LB];

int a[MAXQ], c[MAXQ];

inline int get(int u)
{
	if(!a[u]) return -1;
	for(int i=lb[dep[u]]; i>=0; --i)
		if(i <= lb[dep[u]] && a[anc[u][i]])
			u = anc[u][i];
	return u;
}

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXQ; ++i) lb[i] = lb[i>>1] + 1;
	
	int Q;
	scanf("%d%d%d",&Q,&a[1],&c[1]);
	dep[0] = -1;
	for(int k=1; k<=Q; ++k)
	{
		int oper;
		scanf("%d",&oper);
		if(oper == 1)
		{
			int p, u = k+1;
			scanf("%d%d%d",&p,&a[u],&c[u]);
			++p;
			anc[u][0] = p; dep[u] = dep[p] + 1;
			for(int i=1; i<=lb[dep[u]]; ++i)
				anc[u][i] = anc[anc[u][i-1]][i-1];
		}
		else
		{
			int u,w;
			scanf("%d%d",&u,&w); ++u;
			
			ll ans = 0;
			int ans2 = 0;
			while(w)
			{
				int t = get(u);
				if(t == -1) break;
				int mn = min(w, a[t]);
				w -= mn; a[t] -= mn;
				ans += (ll)mn * c[t];
				ans2 += mn;
			}
			
			printf("%d %lld\n",ans2,ans);
			fflush(stdout);
		}
	}
	return 0;
}