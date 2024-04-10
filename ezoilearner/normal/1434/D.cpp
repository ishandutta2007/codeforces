#include<bits/stdc++.h>
using namespace std;
int n,m;
#define Maxn 500010
int ty[Maxn];
int head[Maxn],v[Maxn<<1],w[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e,int t){
	tot++;v[tot]=e;w[tot]=t;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;w[tot]=t;nxt[tot]=head[e];head[e]=tot;
}

int S,T;
int fuck[Maxn];
void search(int u,int f,int &node){//remember to initial
	if(fuck[u]>fuck[node])node=u;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			fuck[v[i]]=fuck[u]+1;
			search(v[i],u,node);
		}
}

struct Tree{
	int depth[Maxn],dis[Maxn],seq[Maxn],in[Maxn],dfk=0;
	int L[Maxn],R[Maxn];
	void dfs(int u,int f){
		dfk++;in[u]=dfk;seq[dfk]=u;
		for(int i=head[u];i;i=nxt[i])
			if(v[i]^f){
				dis[v[i]]=dis[u]+1;
				depth[v[i]]=depth[u]^ty[w[i]];
				dfs(v[i],u);
				L[w[i]]=in[v[i]];R[w[i]]=dfk;
			}
	}
	int dist[Maxn<<2][2],tag[Maxn<<2];
	void make_tag(int k){
		tag[k]^=1;
		swap(dist[k][0],dist[k][1]);
	}
	void push_up(int k){
		for(int i=0;i<2;++i)dist[k][i]=max(dist[k<<1][i],dist[k<<1|1][i]);
	}
	void push_down(int k){
		if(tag[k]){
			make_tag(k<<1);
			make_tag(k<<1|1);
			tag[k]=0;
		}
	} 
	void Build_Tree(int k,int l,int r){
		if(l==r){
			int u=seq[l];
			dist[k][depth[u]]=dis[u];
			dist[k][depth[u]^1]=-1;
			return;
		}
		int mid=(l+r)>>1;
		Build_Tree(k<<1,l,mid);
		Build_Tree(k<<1|1,mid+1,r);
		push_up(k);
	} 
	void Modify(int k,int l,int r,int L,int R){
		if(l==L&&r==R){
			make_tag(k);
			return;
		}
		push_down(k);
		int mid=(l+r)>>1;
		if(R<=mid)Modify(k<<1,l,mid,L,R);
		else if(mid<L)Modify(k<<1|1,mid+1,r,L,R);
		else{
			Modify(k<<1,l,mid,L,mid);
			Modify(k<<1|1,mid+1,r,mid+1,R);
		}
		push_up(k);
	}
	void mo(int ed){Modify(1,1,n,L[ed],R[ed]);}
	int query(){return dist[1][0];}
}T1,T2;

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

char st[10];int tp;
void print(int x){
	if(!x)putchar('0');
	else{
		while(x){
			st[++tp]=x%10+'0';
			x/=10;
		}
		while(tp)putchar(st[tp--]);		
	}
}

int main(){
	rd(n);
	int s,e,t;
	for(int i=1;i<n;++i){
		rd(s);rd(e);rd(t);
		ty[i]=t;
		add_edge(s,e,i);
	}
	rd(m);
	S=1;search(1,0,S);
	T=S;fuck[T]=0;search(S,0,T);
	T1.dfs(S,0);T1.Build_Tree(1,1,n);
	T2.dfs(T,0);T2.Build_Tree(1,1,n);
	int ed;
	while(m--){
		rd(ed);
		T1.mo(ed);T2.mo(ed);
		int res=max(T1.query(),T2.query());
		print(res);puts("");
	}
	return 0;
}