#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef double db;
const int N=2e5+100;
struct edge{
	int x,y,c,next;
}a[2*N];int len,last[N];
int b[N];
void ins(int x,int y,int c){
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
bool bk[N],bz[N];int size[N],root,tot;
void find(int x,int fa){
	int Max=0;
	size[x]=1;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]&&y!=fa){
			find(y,x);
			size[x]+=size[y];
			if(Max<size[y]) Max=size[y];
		}
	}
	if(Max<tot-size[x]) Max=tot-size[x];
	if(Max<=tot/2) root=x;
}
db Sum[N],deep[N];
void dfs(int x){
	bz[x]=false;
	Sum[x]=0;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bz[y]){
			deep[y]=deep[x]+a[k].c;
			dfs(y);
			Sum[x]+=Sum[y];
		}
	}
	Sum[x]+=(1.5*sqrt(deep[x])*b[x]);
}
db ans2;
void dfs2(int x,int fa,db c){
	ans2+=(c*sqrt(c)*b[x]);
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(y!=fa) dfs2(y,x,c+a[k].c);
	}
}
int Ans;db Ans2=1e21;
void solve(int x){
	find(x,0);
	x=root;
	find(x,0);
	ans2=0;dfs2(x,0,0);
	if(Ans2>ans2) Ans2=ans2,Ans=x;
	memset(bz,true,sizeof(bz));
	deep[x]=0;dfs(x);
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]&&Sum[x]-2*Sum[y]<0)
			{tot=size[y],solve(y);break;}
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
	}
	memset(bk,true,sizeof(bk));
	tot=n;solve(1);
	printf("%d\n",Ans);
	printf("%.10lf\n",Ans2);
	return 0;
}