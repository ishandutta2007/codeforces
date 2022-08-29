#include<bits/stdc++.h>
#define re register
#define ull __uint128_t
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,O[102],head[102],cnt,W[102],cur,tg[102],fa[102],rt,num,pos;
ull pw[102],f[102];
struct edge{int to,next;}e[202];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
struct node{int x;ull y;bool operator <(const node A)const{return y<A.y;};};
priority_queue<node>Q,Q1;
inline bool ck(re int x){
	re ull y=pw[x];Q1=Q;
	for(re int i=x-1;~i&&Q1.size();--i){
		re node tmp=Q1.top();Q1.pop();
		if(tmp.y>=pw[i+1])return 0;
		if((tmp.y&pw[i])&&tmp.y>pw[i])tmp.y^=pw[i],Q1.push(tmp);
	}return Q1.empty();
} 
inline void dfs(re int x,re int y){
	fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)Q.push((node){e[i].to,f[e[i].to]+1});
	for(re int i=n;~i&&Q.size();--i)
		if(!ck(i)){
			re node tmp=Q.top();Q.pop(); 
			if((tmp.y&pw[i])&&tmp.y>pw[i])tmp.y^=pw[i],Q.push(tmp);
			else W[tmp.x]=i;f[x]|=pw[i];
		}
}
inline int ID(re int x,re int y){return fa[x]==y?x:y;}
inline void dfs1(re int x,re int y){
	++num;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y&&!tg[e[i].to]){
			re int z=ID(x,e[i].to);
			if(W[z]>=W[pos])pos=z;
			dfs1(e[i].to,x);
		}
}
int main(){
	n=read(),rt=1;
	for(re int i=pw[0]=1;i<=101;++i)pw[i]=pw[i-1]*2;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,1);
	while(1){
		pos=num=0,dfs1(rt,rt);
		if(num==1){
			printf("! %d",rt);
			return 0;
		}
		printf("? %d %d\n",pos,fa[pos]),fflush(stdout),rt=read();
		if(pos==rt)tg[fa[pos]]=1;
		else tg[pos]=1;
	}
}