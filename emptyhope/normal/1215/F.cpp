#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn 2000055
int n,m,m0,m1;
int idx,scc,bel[maxn],dfn[maxn],low[maxn];
bool ins[maxn];
stack<int>s;
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot,head[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++idx;
	ins[u]=1;s.push(u);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}if(low[u]!=dfn[u])return;
	scc++;int v;
	do{
		v=s.top();s.pop();
		ins[v]=0,bel[v]=scc;
	}while(u!=v);
}

inline int Y(int x){return x<<1;}
inline int N(int x){return x<<1|1;}

inline void link(int x,int y){
	adde(x,y),adde(y^1,x^1);
}

bool work(){
	For(i,1,(n+m+1)*2)if(!dfn[i])tarjan(i);
	For(i,1,n+m+1)if(bel[Y(i)]==bel[N(i)])return 0;
	return 1;
}

int L[400005],R[400005];
signed main()
{
	m0=read(),n=read(),m=read(),m1=read();
	For(i,1,m0){
		int u=read(),v=read();
		link(N(u),Y(v));
	}
	
	For(i,0,m-1) link(Y(n+i+1),Y(n+i+2));
	link(Y(n+1),N(n+1)); // [0] ==  no
	
	For(i,1,n){
		int l=read(),r=read();
		L[i]=l,R[i]=r;
		link(Y(i),N(n+l));
		link(Y(i),Y(n+r+1));
	}
	
	For(i,1,m1){
		int u=read(),v=read();
		link(Y(u),N(v));
	}
	
	if(!work())return puts("-1")&0;
	
	vector<int>o;
	For(i,1,n)if(bel[Y(i)]<bel[N(i)])o.push_back(i);
	int mnl=0;
	for(auto x:o)mnl=max(mnl,L[x]);
	cout<<o.size()<<' '<<mnl<<endl;
	for(auto x:o)cout<<x<<' ';
    return 0;
}