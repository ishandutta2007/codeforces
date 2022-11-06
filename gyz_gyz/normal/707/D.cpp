#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 100010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,q,tot,ans[N],w[N],s[N],t[N];
bitset<2001>a[2010];vector<int>p[N];
void rv(bitset<2001>&a){int r;
	if(!a[2000])r=a.count();else r=m-(2001-a.count());
	tot+=m-r*2;a=~a;
}
void dfs(int x){ans[x]=tot;
	for(int i:p[x]){bool fl=0;
		if(w[i]==1&&!a[s[i]][t[i]]){
			fl=1;a[s[i]][t[i]]=1;++tot;
		}
		if(w[i]==2&&a[s[i]][t[i]]){
			fl=1;a[s[i]][t[i]]=0;--tot;
		}
		if(w[i]==3)rv(a[s[i]]);
		dfs(i);
		if(w[i]==1&&fl){
			a[s[i]][t[i]]=0;--tot;
		}
		if(w[i]==2&&fl){
			a[s[i]][t[i]]=1;++tot;
		}
		if(w[i]==3)rv(a[s[i]]);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,q){
		scanf("%d%d",&w[i],&s[i]);
		if(w[i]==4)p[s[i]].pb(i);else p[i-1].pb(i);
		if(w[i]<3){
			scanf("%d",&t[i]);--t[i];
		}
	}
	dfs(0);rep(i,1,q)printf("%d\n",ans[i]);
}