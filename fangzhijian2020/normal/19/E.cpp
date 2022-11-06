#include<bits/stdc++.h>
using namespace std;
namespace FastIO{
	const int L=1<<21;char buffer[L],*S,*T;
	inline char getchar(){
		if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;
		}return *S++;
	}
	inline int read(){
		char c;int rec=0,f=1;
		for(c=getchar();c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
		while(c>='0'&&c<='9')rec=(rec<<1)+(rec<<3)+(c-'0'),c=getchar();return rec*f;}
}using FastIO::read;
const int N=1e6+10;
struct edge{int to,next;}bian[N<<1];
int first[N],size=1;
void add(int x,int y){
	bian[++size]=(edge){y,first[x]};
	first[x]=size;
}
int n,m;
int dist[N],tag[N];
int cir_cnt=0,te=0;
void dfs(int u,int fe){
	for(int i=first[u];i;i=bian[i].next){
		int to=bian[i].to;
		if(i==(fe^1)) continue;
		if(dist[to]){
			if(dist[u]<dist[to]) continue;
			if((dist[u]-dist[to]+1)&1){
				tag[u]++; tag[to]--;
				cir_cnt++; te=i>>1;
			}else{
				tag[u]--; tag[to]++;
			}
		}else{
			dist[to]=dist[u]+1;
			dfs(to,i);
			tag[u]+=tag[to];
		}
	}
}
vector<int>Ans;
bool vis[N];
void DFS(int u){
	vis[u]=1;
	for(int i=first[u];i;i=bian[i].next){
		int to=bian[i].to;
		if(vis[to]) continue;
		if(tag[to]==cir_cnt) Ans.push_back(i>>1);
		DFS(to);
	}
}
int main(){
//	freopen("in.in","r",stdin);
	int size=40<<21;//40M
	//__asm__ ("movl  %0, %%esp\n"::"r"((char*)malloc(size)+size));// 
//	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));// 
	n=read(); m=read();
	int self_cir=0;
	for(int i=1,u,v;i<=m;++i){
		u=read(); v=read();
		if(u==v) {
			if(self_cir==0) self_cir=i;
			else self_cir=-1;
		}
		else add(u,v),add(v,u);
	}
	if(self_cir==-1){puts("0");exit(0);}
	
	for(int i=1;i<=n;++i){
		if(!dist[i]) dist[i]=1,dfs(i,0);
	}
	if(!cir_cnt){
		if(self_cir) {puts("1");cout<<self_cir<<'\n';exit(0);}
		else{
			cout<<m<<'\n';
			for(int i=1;i<=m;++i) cout<<i<<' ';
			return 0;
		}
	}
	if(self_cir) puts("0"),exit(0);
	for(int i=1;i<=n;++i)
		if(!vis[i]) DFS(i);
	if(cir_cnt==1) Ans.push_back(te);
	sort(Ans.begin(),Ans.end());
	cout<<Ans.size()<<'\n';
	for(int i=0;i<Ans.size();++i) cout<<Ans[i]<<' ';cout<<'\n';
	exit(0);
}