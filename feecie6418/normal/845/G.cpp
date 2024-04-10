#include<cstdio>
#include<iostream>
#include<cstring>
#define mod 10086
using namespace std;
int n,m,h[100005],cnt,used[100005];
long long p[70],z,ans,f[100005];
struct Edge{
	int to,next;
	long long value;
}e[200005];
void Add_Edge(int x,int y,long long z){
	e[++cnt]=(Edge){y,h[x],z};
	h[x]=cnt;
}
void Insert(long long x){
	for(int i=63;i>=0;i--){
		if(!(x&(1ll<<i)))continue;
		if(!p[i]){
			p[i]=x;
			return ;
		}
		else x^=p[i];
	}
}
void DFS(int now,long long xors){
	f[now]=xors,used[now]=1;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(!used[y])DFS(y,xors^e[i].value);
		else Insert(f[now]^e[i].value^f[y]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&z);
		Add_Edge(x,y,z),Add_Edge(y,x,z);
	}
	DFS(1,0),ans=f[n];
	for(int i=63;i>=0;i--)ans=min(ans,ans^p[i]);
	printf("%lld\n",ans);
}