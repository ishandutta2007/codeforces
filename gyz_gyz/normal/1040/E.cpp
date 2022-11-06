#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 1000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,k,nw,ls;ll ans,w[N];bool v[N];
vector<int>p[N];
struct pr{int x,y;ll z;}e[N];
bool cmp(pr x,pr y){return x.z<y.z;}
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
void dfs(int x){v[x]=1;
	for(auto i:p[x])if(!v[i]){nw--;dfs(i);}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%I64d",&w[i]);
	rep(i,1,m){
		scanf("%d%d",&e[i].x,&e[i].y);
		e[i].z=w[e[i].x]^w[e[i].y];
	}
	sort(e+1,e+m+1,cmp);ls=1;ans=qk(2,n+k);
	rep(i,1,m){
		p[e[i].x].pb(e[i].y);p[e[i].y].pb(e[i].x);
		if((i==m)||(e[i].z!=e[i+1].z)){nw=n;
			rep(j,ls,i){
				if(!v[e[j].x])dfs(e[j].x);
				if(!v[e[j].y])dfs(e[j].y);
			}
			ans=(ans+mo+qk(2,nw)-qk(2,n))%mo;
			rep(j,ls,i){
				v[e[j].x]=v[e[j].y]=0;
				p[e[j].x].clear();p[e[j].y].clear();
			}ls=i+1;
		}
	}
	printf("%I64d\n",ans);
}