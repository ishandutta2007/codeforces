#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
#define Maxn 600010
char ch[Maxn];
int pos[Maxn];
struct node{
	int son[27],fa;
	int len;
	int id;
}tree[Maxn*2];
int cnt=1,last=1;
void insert(int dir,int id){
	int k=last,now=++cnt;
	tree[now].id=id;
	tree[now].len=tree[k].len+1;
	while(k&&!tree[k].son[dir])tree[k].son[dir]=now,k=tree[k].fa;
	if(!k)tree[now].fa=1;
	else{
		int q=tree[k].son[dir];
		if(tree[q].len==tree[k].len+1)tree[now].fa=q;
		else{
			int nq=++cnt;
			tree[nq]=tree[q];tree[nq].id=0;
			tree[nq].len=tree[k].len+1;
			tree[now].fa=tree[q].fa=nq;
			while(k&&tree[k].son[dir]==q)tree[k].son[dir]=nq,k=tree[k].fa;
		}
	}
	last=now;
}
int head[Maxn*2],v[Maxn*2],nxt[Maxn*2],tot=0;
int fa[Maxn*2][20];
int root[Maxn*2];
struct Node{
	int ls,rs;
	int mx,at;
	int sum;
	bool leaf(){return !ls&&!rs;}
}T[Maxn*34];
int Cnt=0;
void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
void push_up(int k){
	T[k].mx=T[T[k].rs].mx;
	T[k].at=T[T[k].rs].at;
	if(T[T[k].ls].mx>=T[k].mx){
		T[k].mx=T[T[k].ls].mx;
		T[k].at=T[T[k].ls].at;
	}
	T[k].sum=T[T[k].ls].sum+T[T[k].rs].sum;
}
void insert(int &k,int l,int r,int x){
	k=++Cnt;
	if(l==r){
		T[k].mx=1;
		T[k].at=l;
		T[k].sum=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)insert(T[k].ls,l,mid,x);
	else insert(T[k].rs,mid+1,r,x);
	push_up(k);
}
int merge(int u,int v){
	if(!u||!v)return u|v;
	int k=++Cnt;
	T[k].ls=merge(T[u].ls,T[v].ls);
	T[k].rs=merge(T[u].rs,T[v].rs);
	T[k].sum=T[u].sum+T[v].sum;
	if(T[k].leaf())T[k].mx=T[k].sum,T[k].at=T[u].at;
	else push_up(k);
	return k;
}
void Dfs(int u,int f){
	fa[u][0]=f;
	for(int i=1;i<=19;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	if(tree[u].id)insert(root[u],1,m,tree[u].id);
	for(int i=head[u];i;i=nxt[i]){
		Dfs(v[i],u);
		root[u]=merge(root[u],root[v[i]]);
	}
}
int get_pos(int l,int r){
	int k=pos[r],len=r-l+1;
	for(int i=19;i>=0;--i)
	if(tree[fa[k][i]].len>=len)k=fa[k][i];
	return k;
}
Node Add(Node A,Node B){
	Node ans;
	ans.mx=B.mx;
	ans.at=B.at;
	if(A.mx>=ans.mx){
		ans.mx=A.mx;
		ans.at=A.at;
	}
	return ans;
}
Node Query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return T[k];
	int mid=(l+r)>>1;
	if(R<=mid)return Query(T[k].ls,l,mid,L,R);
	else if(mid<L)return Query(T[k].rs,mid+1,r,L,R);
	else return Add(Query(T[k].ls,l,mid,L,mid),Query(T[k].rs,mid+1,r,mid+1,R));
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	scanf("%s",ch+1);
	int len=strlen(ch+1);
	for(int i=1;i<=len;++i)insert(ch[i]-'a',0),pos[i]=last;
	insert(26,0);
	rd(m);
	for(int i=1;i<=m;++i){
		scanf("%s",ch+1);
		len=strlen(ch+1);
		for(int j=1;j<=len;++j)insert(ch[j]-'a',i);
		insert(26,0);
	}
	for(int i=2;i<=cnt;++i)add_edge(tree[i].fa,i);
	Dfs(1,0);
	rd(q);
	int l1,r1,l2,r2;
	for(int i=1;i<=q;++i){
		rd(l1);rd(r1);rd(l2);rd(r2);
		int k=get_pos(l2,r2);
		Node Ans=Query(root[k],1,m,l1,r1);
		if(!Ans.mx)printf("%d %d\n",l1,0);
		else printf("%d %d\n",Ans.at,Ans.mx);
	}
	return 0;
}