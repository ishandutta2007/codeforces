#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 1000010 
#define cout cerr
#define FR first
#define SE second
int p[Maxn];
bool vis[Maxn];
int num[Maxn][2],pos[Maxn][2];
int h[Maxn];

int to(int x){
	if(x<=n)return x;
	return x-n;
}
int fr;
void hh(int x,int y){
	if(to(num[x][0])==to(y))h[x]=0;
	else h[x]=1;
}
void dfs(int u){
	int x=num[u][h[u]^1];
	if(pos[to(x)][0]!=u){
		hh(pos[to(x)][0],x);
		if(pos[to(x)][0]!=fr)dfs(pos[to(x)][0]);
	}else{
		hh(pos[to(x)][1],x);
		if(pos[to(x)][1]!=fr)dfs(pos[to(x)][1]);
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	scanf("%d",&n);
	if(n%2==0){
		puts("First");
		for(int i=1;i<=2*n;++i)
			if(i<=n)printf("%d ",i);
			else printf("%d ",i-n);
		fflush(stdout);
		int x;scanf("%d",&x);
		return 0;
	}
	puts("Second");
	fflush(stdout);
	int x;
	for(int i=1;i<=2*n;++i){
		scanf("%d",&x);
		if(!num[x][0])num[x][0]=i;
		else num[x][1]=i;
		if(!pos[to(i)][0])pos[to(i)][0]=x;
		else pos[to(i)][1]=x;
	}
	memset(h,-1,sizeof(int)*(n+1));
	for(int i=1;i<=n;++i)
		if(h[i]==-1){
			h[i]=0;fr=i;
			dfs(i);
		}
	int res=0;
	for(int i=1;i<=n;++i)res=(res+num[i][h[i]])%(2*n);
	if(res)
		for(int i=1;i<=n;++i)h[i]^=1;
	for(int i=1;i<=n;++i)printf("%d ",num[i][h[i]]);
	puts("");
	fflush(stdout);
	scanf("%d",&x);
	return 0;
}