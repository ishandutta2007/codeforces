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
int n,m,st[N],nt[N],p[N],v[N];
void dfs(int x){
	for(int i=st[x];i;i=nt[i]){
		if(v[p[i]]==v[x])exit(printf("NO\n")*0);
		if(!v[p[i]]){
			v[p[i]]=-v[x];dfs(p[i]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		nt[i*2-1]=st[x];st[x]=i*2-1;p[i*2-1]=y;
		nt[i*2]=st[y];st[y]=i*2;p[i*2]=x;
	}
	rep(i,1,n)if(!v[i]){
		v[i]=1;dfs(i);
	}
	printf("YES\n");
	rep(i,1,m)printf("%d",v[p[i*2]]>0);
}