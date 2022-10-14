#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+10,M=1e5+10;
queue<int>Q;
char st[N],a[M];
int n,m,q,last,tot,qwq,pl[N],pos[N];
struct ele{int ls,rs;P v;}t[M<<4];
int fa[M],len[M],ch[M][26],rt[M],f[20][M],d[M];
V cpy(int x,int y){FOR(i,0,25)ch[x][i]=ch[y][i];}
V ins(int x){
	int p(last),np,q,nq;
	if(len[ch[p][x]]==len[p]+1)return void(last=ch[p][x]);
	len[last=np=++tot]=len[p]+1;
	while(p&&ch[p][x]==0)ch[p][x]=np,p=fa[p];
	if(len[q=ch[p][x]]==len[p]+1)return void(fa[np]=q);
	cpy(nq=++tot,q),fa[nq]=fa[q],len[fa[np]=fa[q]=nq]=len[p]+1;
	while(p&&ch[p][x]==q)ch[p][x]=nq,p=fa[p];
}
#define lc t[p].ls
#define rc t[p].rs
#define lson lc,L,mid
#define rson rc,mid+1,R
#define root(p) rt[p],1,m
V upd(int p){t[p].v=max(t[lc].v,t[rc].v);}
V add(int&p,int L,int R,int x){
	if(!p)p=++qwq,t[p].v.second=-L;
	if(L==R)return void(t[p].v.first++);
	int mid=L+R>>1;
	x<=mid?add(lson,x):add(rson,x),upd(p);
}
I merge(int x,int y,int L,int R){
	if(!x||!y)return x|y;
	int p=++qwq,mid=L+R>>1;
	if(L==R)return t[p].v=P(t[x].v.first+t[y].v.first,-L),p;
	t[p].ls=merge(t[x].ls,t[y].ls,L,mid);
	t[p].rs=merge(t[x].rs,t[y].rs,mid+1,R);
	return upd(p),p;
}
P ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p].v;
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return max(ask(lson,l,mid),ask(rson,mid+1,r));
}
V input(int l=0){
	scanf("%s%d",st+1,&m),len[0]=-1,tot=1,n=strlen(st+1);
	FOR(i,0,25)ch[0][i]=1;
	FOR(i,1,m){
		scanf("%s",a+1),last=1,l=strlen(a+1);
		FOR(j,1,l)ins(a[j]-'a'),add(root(last),i);
	}
}
V init(int l=0,int p=1,int x=0){
	FOR(i,1,n){
		for(x=st[i]-'a';p&&!ch[p][x];l=len[p])p=fa[p];
		pl[i]=++l,pos[i]=p=ch[p][x];
	}
	FOR(i,1,tot)d[f[0][i]=fa[i]]++;
	FOR(i,0,18)FOR(j,1,tot)f[i+1][j]=f[i][f[i][j]];
	FOR(i,1,tot)if(!d[i])Q.push(i);
	for(int x;!Q.empty();Q.pop()){
		if(fa[x=Q.front()]&&!--d[fa[x]])Q.push(fa[x]);
		rt[fa[x]]=merge(rt[fa[x]],rt[x],1,m);
	}
}
V solve(int l,int r,int L,int R){
	int vl=R-L+1,p=pos[R];
	if(pl[R]<vl)return void(cout<<l<<" 0\n");
	ROF(i,19,0)if(len[f[i][p]]>=vl)p=f[i][p];
	P x=ask(root(p),l,r);
	if(!x.first)cout<<l<<" 0\n";
	else cout<<-x.second<<' '<<x.first<<'\n';
}
V work(){
	for(int L,R,l,r=scanf("%d",&q);q--;solve(L,R,l,r))
		scanf("%d%d%d%d",&L,&R,&l,&r);
}
int main(){
	input();
	init();
	work();
	return 0;
}