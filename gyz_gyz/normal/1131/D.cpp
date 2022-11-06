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
#define N 2010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,s,t;char w[N][N];
bool p[N][N];int r[N],d[N],h[N],f[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",w[i]+1);
	rep(i,1,n+m)f[i]=i;
	rep(i,1,n)rep(j,1,m)if(w[i][j]=='=')
		if(gf(i)!=gf(j+n))f[gf(j+n)]=gf(i);
	rep(i,1,n)rep(j,1,m){
		int x=gf(i),y=gf(j+n);
		if(w[i][j]=='<'){
			if(x==y||p[x][y])return printf("No\n"),0;
			if(!p[y][x])p[y][x]=1,++r[y];
		}
		if(w[i][j]=='>'){
			if(x==y||p[y][x])return printf("No\n"),0;
			if(!p[x][y])p[x][y]=1,++r[x];
		}
	}
	rep(i,1,n+m)if(gf(i)==i&&!r[i])h[i]=1,d[++t]=i;
	for(s=1;s<=t;++s)
		rep(i,1,n+m)if(p[i][d[s]]&&!--r[i])
			d[++t]=i,h[i]=h[d[s]]+1;
	rep(i,1,n+m)if(f[i]==i&&!h[i])return printf("No\n"),0;
	printf("Yes\n");
	rep(i,1,n)printf("%d ",h[gf(i)]);printf("\n");
	rep(i,1,m)printf("%d ",h[gf(i+n)]);
}