#include<bits/stdc++.h>
using namespace std;

const int N=210;
int p[N],ID[N],g[N],b[N];
bool bk[N],vis[N];

struct edge{
	int x,y,c,next;
}a[2*N];int len,last[N];

void ins(int x,int y,int c){
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
void dfs(int x){
	vis[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(vis[y]){
			b[y]=a[k].c;
			dfs(y);
		}
	}
}

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]),ID[p[i]]=i;
		
		memset(bk,true,sizeof(bk));
		int tot=0;
		for(int i=1;i<=n;i++)
			if(bk[i]){
				tot++;int t=i;
				while(bk[t]) bk[t]=false,g[t]=tot,t=p[t];
			}
			
		len=0;memset(last,0,sizeof(last));
		for(int i=1;i<n;i++){
			if(g[i]!=g[i+1]){
				ins(g[i],g[i+1],i);
				ins(g[i+1],g[i],i);
			}
		}
		memset(vis,true,sizeof(vis));
		dfs(1);
		sort(b+2,b+tot+1,cmp);
		
		int las=b[2];
		for(int i=2;i<=tot;i++){
			p[ID[b[i]]]=b[i]+1;
			if(i==tot||b[i]+1!=b[i+1]){
				p[ID[b[i]+1]]=las;
				las=b[i+1];
			}
		}
		
		for(int i=1;i<=n;i++) ID[p[i]]=i;
		int t=1;
		for(int i=1;i<=n;i++) printf("%d ",t),t=ID[t];
		printf("\n");
	}
	
	return 0;
}