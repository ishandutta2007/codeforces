#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define N 250010
#define M 10000010
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
vector<pil>bl[N];int n,m;
int h[M],l[M],r[M],f[M],d[M];ll c[M],a[M];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){int tot=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int k;
		scanf("%d",&k);
		rep(j,0,k-1){int x;
			scanf("%d",&x);bl[i].pb({x,0});
		}
		rep(j,0,k-1)scanf("%lld",&bl[i][j].sc);
	}
	int k;scanf("%d",&k);
	while(k--){int x;ll y;
		scanf("%d%lld",&x,&y);
		for(pil i:bl[x])h[++tot]=i.fr,c[tot]=i.sc*y;
	}int t=0;
	rep(i,1,m){l[i]=i;
		while(t&&i-d[t]<h[i])l[i]=l[d[t--]];
		d[++t]=i;
	}t=0;
	dep(i,m,1){r[i]=i;
		while(t&&d[t]-i<h[i])r[i]=r[d[t--]];
		d[++t]=i;
	}
	rep(i,1,m)a[i]=Inf,f[i]=i;t=0;
	rep(i,1,m){
		a[r[i]]=min(a[r[i]],a[i-1]+c[i]);
		a[i]=min(a[i],a[gf(l[i]-1)]+c[i]);
		for(l[i]=i-1;a[i]<=a[l[i]];l[i]=l[l[i]])f[l[i]]=i;
	}
	printf("%lld\n",a[m]);
}