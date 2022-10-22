#include<bits/stdc++.h>
using namespace std;
int n,m;
#define Maxn 300010
int a[Maxn],b[Maxn];
int fa[Maxn];
struct Edge{
	int s,e,t;
	bool operator <(const Edge &z)const{return t>z.t;}
}edge[Maxn];int len=0;

int getroot(int x){
	if(fa[x]!=x)fa[x]=getroot(fa[x]);
	return fa[x];
} 

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=m;++i){
		int t,x;
		scanf("%d",&t);
		for(int j=1;j<=t;++j){
			scanf("%d",&x);
			edge[++len]=(Edge){i,m+x,a[i]+b[x]};
		}
	}
	sort(edge+1,edge+len+1);
	long long ans=0;
	for(int i=1;i<=m+n;++i)fa[i]=i;
	for(int i=1;i<=len;++i){
		int fx=getroot(edge[i].s),fy=getroot(edge[i].e);
		fa[fx]=fy;
		if(fx==fy)ans+=edge[i].t;
	}
	printf("%lld\n",ans);
	return 0;
}