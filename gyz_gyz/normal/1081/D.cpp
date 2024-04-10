#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
struct pr{int x,y,z;}e[N];
bool cmp(pr x,pr y){return x.z<y.z;}
int n,m,k,f[N],s[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)f[i]=i;
	rep(i,1,k){int x;
		scanf("%d",&x);s[x]=1;
	}
	rep(i,1,m)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+m+1,cmp);
	rep(i,1,m)if(gf(e[i].x)!=gf(e[i].y)){
		if((s[f[e[i].x]]+=s[f[e[i].y]])==k){
			rep(j,1,k)printf("%d ",e[i].z);return 0;
		}f[f[e[i].y]]=f[e[i].x];
	}
}