#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define dec(x,y) x=(x+mo-(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 200000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,tot,x,y,f[N],id[N];double ans,z,a[N],s[N];
vector<int>p[N];
void dfs(int x){
	ans+=a[f[x]]*(1-a[x]);
	for(auto i=p[x].begin();i!=p[x].end();i++)if(*i==f[x]){
		p[x].erase(i);break;
	}
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;id[i]=++tot;
	}
	for(auto i:p[x])if(i!=f[x])dfs(i);
}
void fx(int x,double y){
	for(;x<N;x+=x&(-x))s[x]+=y;
}
double q(int x){double y=0;
	for(;x;x-=x&(-x))y+=s[x];return y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lf",&a[i]);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);x++;y++;
		p[x].pb(y);p[y].pb(x);
	}
	a[0]=1;tot=id[1]=1;dfs(1);
	rep(i,1,n)fx(id[i],1-a[i]);
	for(scanf("%d",&m);m;m--){
		scanf("%d%lf",&x,&z);x++;
		ans+=a[f[x]]*(a[x]-z);fx(id[x],a[x]-z);
		if(p[x].size())ans+=(z-a[x])*(q(id[*(--p[x].end())])-q(id[*p[x].begin()]-1));
		a[x]=z;printf("%.5lf\n",ans);
	}		
}