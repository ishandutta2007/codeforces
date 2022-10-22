#include<cstdio>
#include<cstring>
using namespace std;
const int N=1100,maxn=1000;
struct edge{
	int x,y,next;
}a[N*N];int len,last[N];bool bk[N];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
void dfs(int x){
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) dfs(y);
	}
}
bool bz[50][50];int qz[2][50];
int main()
{
	/*len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=maxn;i++)
		for(int j=1;j<=maxn;j++)
			if((i&j)==j&&i+j<=maxn) ins(i,i+j);*/
	int T;scanf("%d",&T);
	while(T--){
		int x,y;bool pd=true;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=30;i++){
			qz[0][i]=qz[0][i-1]+((x&(1<<(i-1)))>0);
			qz[1][i]=qz[1][i-1]+((y&(1<<(i-1)))>0);
			if(qz[0][i]<qz[1][i]) pd=false;
		}
		/*memset(bk,true,sizeof(bk));
		dfs(x);
		if(!bk[y]) printf("YES\n");
		else printf("NO\n");*/
		if(x>y) pd=false;
		if(!pd) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}