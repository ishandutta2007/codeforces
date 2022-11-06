#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=200011;
struct Edge{
	int v;Edge *nxt;
} pl[N<<1],*cur=pl,*G[N];
void ins(int u,int v){
	cur->v=v,cur->nxt=G[u],G[u]=cur++; 
}
int In[N],Ou[N],n,b[N];
void dfs(int x){
	static int dfs_cnt;
	In[x]=++dfs_cnt;
	b[dfs_cnt]=x;
	Es(x,i)dfs(i->v);
	Ou[x]=dfs_cnt;
}
int a[N];
struct Node{
	int sz,tot;
	bool tag;
	int revr(){
		tag^=1;
		tot=sz-tot;
	}
}T[N<<2];
#define All 1,1,n
#define mid (L+R>>1)
#define lson o<<1,L,mid
#define rson o<<1|1,mid+1,R
inline void push_up(int o) {
	T[o].tot=T[o<<1].tot+T[o<<1|1].tot;
}
inline void push_down(int o){
	if(T[o].tag){
		T[o<<1].revr(),T[o<<1|1].revr();
		T[o].tag=0;
	}
}
void build(int o,int L,int R){
	T[o].sz=R-L+1;
	if(L==R)T[o].tot=a[b[L]];
	else{
		build(lson),build(rson);
		push_up(o);
	}
}
void updata(int o,int L,int R,int l,int r){
	if(L==l&&R==r)T[o].revr();
	else{
		push_down(o);
		if(r<=mid)updata(lson,l,r);
		else if(l>mid)updata(rson,l,r);
		else updata(lson,l,mid),updata(rson,mid+1,r);
		push_up(o);
	}
}
int query(int o,int L,int R,int l,int r){
	if(L==l&&R==r)return T[o].tot;
	else{
		push_down(o);
		if(r<=mid)return query(lson,l,r);
		else if(l>mid)return query(rson,l,r);
		else return query(lson,l,mid)+query(rson,mid+1,r);
	}
}
char ch[99];
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd();
	rep(i,2,n){
		int fa=rd();
		ins(fa,i);
	}
	dfs(1);
	rep(i,1,n)a[i]=rd();
	build(All);
	int q=rd();
	while(q--){
		scanf("%s",ch);
		int x=rd();
		if(ch[0]=='g')printf("%d\n",query(All,In[x],Ou[x]));
		else updata(All,In[x],Ou[x]);
	}
}