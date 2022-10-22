#include<cstdio>
#include<cstring>
using namespace std;

const int N=2e5+100;
int b[N];
struct edge{
	int x,y,next;
}a[2*N];int len,last[N];

void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}

bool bk[N];int Sum=0,L[N],R[N],id[N];
void dfs(int x){
	bk[x]=false;id[++R[Sum]]=x;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]) dfs(y);
	}
}

int Ans[N][2],tot=0;
void add(int x,int y) {Ans[++tot][0]=x;Ans[tot][1]=y;}

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++) ins(i,b[i]);
	
	memset(bk,true,sizeof(bk));
	for(int i=1;i<=n;i++)
		if(bk[i]){
			Sum++;
			L[Sum]=R[Sum-1]+1;
			R[Sum]=R[Sum-1];
			dfs(i);
		}
		
	if(Sum==1){
		add(id[n-1],id[n]);
		for(int i=1;i<n-2;i++) add(id[n-1],id[i]);
		add(id[n-2],id[n]);
		add(id[n-2],id[n-1]);
		add(id[n],id[n-1]);
	}
	
	else{
		for(int i=1;i<=Sum;i+=2){
			if(i<Sum){
				add(id[L[i]],id[L[i+1]]);
				for(int j=L[i];j<R[i];j++) add(id[L[i+1]],id[j+1]);
				for(int j=L[i+1];j<R[i+1];j++) add(id[L[i]],id[j+1]);
				add(id[L[i]],id[L[i+1]]);
			}
			else{
				add(id[1],id[L[i]]);
				for(int j=L[i];j<R[i];j++) add(id[1],id[j+1]);
				add(id[1],id[L[i]]);
			}
		}
	}
	
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d\n",Ans[i][0],Ans[i][1]);
	
	return 0;
}