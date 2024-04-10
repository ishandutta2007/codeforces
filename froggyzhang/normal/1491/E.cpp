#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int fib[20],n,ok[N];
int ecnt,head[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void Add(int a,int b){
	edge[++ecnt]={b,head[a]};
	head[a]=ecnt;
}
int vis[N<<1],E,siz[N];
pair<int,int> qwq;
void dfs(int u,int fa,int tot){
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[i>>1]||v==fa)continue;
		dfs(v,u,tot);
		if(!~qwq.first&&ok[siz[v]]&&ok[tot-siz[v]]){
			qwq={v,u},E=i;
		}
		siz[u]+=siz[v];
	}
}		
bool check(int u,int S){
	if(S==1)return true;
	qwq={-1,-1};
	dfs(u,0,S);
	if(!~qwq.first)return false;
	int x=qwq.first,y=qwq.second;
	vis[E>>1]=1;
	int s1=siz[x],s2=S-siz[x];
	return check(x,s1)&&check(y,s2);
}
int main(){
	n=read();
	fib[0]=fib[1]=1;
	ok[1]=1;
	for(int i=2;;++i){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>n)break;
		ok[fib[i]]=1;
	}
	ecnt=1;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		Add(u,v),Add(v,u);
	}	
	printf(ok[n]&&check(1,n)?"YES\n":"NO\n");
	return 0;
}