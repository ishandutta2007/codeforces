#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
struct data{int to,next;}e[N<<1];int n,m,cnt,i,j,K,h[N],q[N],flag,u,v,t,w,a[N],ans1,ans2;
struct graph{
	int head[N];
	void ins(int u,int v){e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
}g1,g2;
void bfs(int S){
	memset(h,-1,sizeof(h));t=0;w=1;q[0]=S;h[S]=0;
	while(t!=w){
		int x=q[t++];for(int i=g2.head[x];i;i=e[i].next)if(h[e[i].to]==-1)q[w++]=e[i].to,h[e[i].to]=h[x]+1;
	}
}
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=m;++i)scanf("%d%d",&u,&v),g1.ins(u,v),g2.ins(v,u);
	for(scanf("%d",&K),i=1;i<=K;++i)scanf("%d",a+i);bfs(a[K]);
	for(i=1;i<K;++i){
		if(h[a[i]]!=h[a[i+1]]+1)ans1++,ans2++;
		else{
			for(j=g1.head[a[i]];j;j=e[j].next)if(h[a[i]]==h[e[j].to]+1&&e[j].to!=a[i+1]){
				ans2++;break;
			} 
		}
	}printf("%d %d\n",ans1,ans2);
}