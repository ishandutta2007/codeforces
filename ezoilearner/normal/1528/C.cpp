#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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


int n;
#define Maxn 300010
int in[Maxn],out[Maxn],dfk=0;
namespace T2{
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
void dfs(int u,int f){
	in[u]=++dfk;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			dfs(v[i],u);
		}
	out[u]=dfk;
}
void init(){
		tot=0;memset(head,0,sizeof(int)*(n+1));
	}
}

struct cmp
{
    bool operator()(const int &L,const int &R)const{
        return	in[L]<in[R];
    }
};

set<int,cmp> S;
bool vis[Maxn];
int Ans;

set<int,cmp>::iterator it,p;

void Add(int u){
	vis[u]=0;
	if(S.size()==0){
		vis[u]=1;S.insert(u);
		Ans=1;return;
	}
	S.insert(u);
	it=S.find(u);p=it;p++;
	if(p!=S.end()){
		it++;
		int t=(*it);
		if(in[t]<=out[u])vis[u]=0;
		else vis[u]=1;
		it--;
	}else vis[u]=1;
	Ans+=vis[u];
	if(it!=S.begin()){
		it--;
		int t=(*it);
		Ans-=vis[t];
		if(in[u]<=out[t])vis[t]=0;
		else vis[t]=1;
		Ans+=vis[t];
	}
}

void Del(int u){
	Ans-=vis[u];
	it=S.find(u);
	if(it!=S.begin()){
		it--;int t=(*it);
		Ans-=vis[t];
		S.erase(u);p=it;p++;
		if(p==S.end())vis[t]=1;
		else{
			it++;
			int y=(*it);
			if(in[y]<=out[t])vis[t]=0;
			else vis[t]=1;
		}
		Ans+=vis[t];
	}else S.erase(u);
}

namespace T1{
	int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
	int res=0;
	void dfs(int u,int f){
		Add(u);res=max(res,Ans);
		for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			dfs(v[i],u);
		}
		Del(u);
	}
	void calc(){
		res=0;Ans=0;S.clear();
		dfs(1,0);
		printf("%d\n",res);
	}
	void init(){
		tot=0;memset(head,0,sizeof(int)*(n+1));
	}
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);int x;
		dfk=0;
		T1::init();T2::init();
		rep(i,2,n){
			rd(x);
			T1::add_edge(x,i);
		}
		rep(i,2,n){
			rd(x);
			T2::add_edge(x,i);
		}
		T2::dfs(1,0);
		T1::calc();
	}
	return 0;
}