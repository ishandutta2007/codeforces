#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
const int T=700;
int n,q;
#define Maxn 600010
#define cout cerr
#define FR first
#define SE second
int a[Maxn];
int ans[Maxn];
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int in[Maxn],out[Maxn],dfk=0;
int seq[Maxn];
int fa[Maxn][19],depth[Maxn];
void go_up(int &k,int d){
	per(i,18,0)
		if(d&(1<<i))k=fa[k][i];
}
int LCA(int a,int b){
	if(depth[a]>depth[b])go_up(a,depth[a]-depth[b]);
	if(depth[a]<depth[b])go_up(b,depth[b]-depth[a]); 
	if(a==b)return a;
	per(i,18,0)
		if(fa[a][i]!=fa[b][i]){
			a=fa[a][i];
			b=fa[b][i];
		}
	return fa[a][0];
}
void dfs(int u,int f){
	in[u]=++dfk;seq[dfk]=u;
	rep(i,1,18)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			depth[v[i]]=depth[u]+1;fa[v[i]][0]=u;
			dfs(v[i],u);
		}
	out[u]=++dfk;seq[dfk]=u;
}

int bel[Maxn];
struct Seg{
	int l,r,lca,id;
	int tl,tr;
	Seg(){l=r=id=0;lca=-1;}
	Seg(int _l,int _r,int _lca,int _id,int _tl,int _tr){l=_l;r=_r;lca=_lca;id=_id;tl=_tl;tr=_tr;}
	bool operator <(const Seg &t)const{
		if(bel[l]!=bel[t.l])return l<t.l;
		return r<t.r;
	}
}seg[Maxn];

int type[Maxn],num[Maxn],p[Maxn];
int sum[Maxn];
void gao(int t){
	p[t]^=1;
	sum[(t+T-1)/T]+=p[t];sum[(t+T-1)/T]-=(p[t]^1);
} 
int query(int t){
	int res=0;
	per(i,t,(t/T)*T+1)
		if(p[i])return i;
	per(i,t/T,1)
		if(sum[i]){
			per(j,i*T,(i-1)*T+1)if(p[j])return j;
		}
	return -1;
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
	rd(n);rd(q);
	int s,e;
	rep(i,1,n)rd(a[i]);
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	}
	dfs(1,0);
	rep(i,1,dfk)bel[i]=i/T+1;
	rep(i,1,q){
		rd(s);rd(e);
		if(in[s]>in[e])swap(s,e);
		if(out[e]<=out[s]){
			seg[i].l=in[s];seg[i].r=in[e];
			seg[i].lca=-1;
		}else{
			seg[i].l=out[s];seg[i].r=in[e];
			seg[i].lca=LCA(s,e);
		}
		seg[i].id=i;
		rd(seg[i].tl);rd(seg[i].tr);
	}
	sort(seg+1,seg+q+1);
	int L=1,R=0;
	rep(i,1,q){
		while(R<seg[i].r){
			R++;
			gao(a[seq[R]]);	}
		while(seg[i].l<L){
			L--;
			gao(a[seq[L]]);
		}
			while(R>seg[i].r){
			
			gao(a[seq[R]]);R--;	}
		while(L<seg[i].l){
			gao(a[seq[L]]);L++;
		}
		if(seg[i].lca!=-1)gao(a[seg[i].lca]);
		ans[seg[i].id]=query(seg[i].tr);
		if(ans[seg[i].id]<seg[i].tl)ans[seg[i].id]=-1;
		if(seg[i].lca!=-1)gao(a[seg[i].lca]);
		
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}