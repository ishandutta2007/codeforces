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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,d[N],st[N],nt[N],p[N],c[N];
void dfs(int x,int y,int f){
	int nw=0;
	for(int i=st[x];i;i=nt[i])if(p[i]!=f){
		++nw;if(y==nw)++nw;
		if(nw>d[n-m])nw=1;
		c[i/2]=nw;dfs(p[i],nw,x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		++d[x];++d[y];
		if(st[x])nt[i*2]=st[x];
		st[x]=i*2;p[i*2]=y;
		if(st[y])nt[i*2+1]=st[y];
		st[y]=i*2+1;p[i*2+1]=x;
	}
	sort(d+1,d+n+1);
	printf("%d\n",d[n-m]);dfs(1,0,0);
	rep(i,1,n-1)printf("%d ",c[i]);
}