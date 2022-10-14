#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=3e5+2; 
const char ans[2][10]={"NO\n","YES\n"};
char st[N];
ll pw[N],val[N];
int n,m,tot,rt[N],pos[N];
struct ele{int ls,rs;ll s;}t[N<<5];
V input(){scanf("%d%d%s",&n,&m,st+1),pw[0]=1;}
#define lc t[p].ls
#define rc t[p].rs
#define lson lc,L,mid
#define rson rc,mid+1,R
#define root(p) rt[p],0,n
V add(int&p,int L,int R,int x,ll w){
	if(t[++tot]=t[p],t[p=tot].s+=w,L==R)return;
	int mid=L+R>>1;
	x<=mid?add(lson,x,w):add(rson,x,w);
}
V init(ll x=233){
	mt19937_64 seed(time(0));
	FOR(i,1,n)val[i]=seed(),pw[i]=pw[i-1]*x;
	FOR(i,1,n){
		rt[i]=rt[i-1],x=st[i]-'a';
		add(root(i),pos[x],pw[n-pos[x]]*(i-pos[x])),pos[x]=i;
	}
}
ll ask(int p,int L,int R,int l,int r){
	if(l==L&&R==r)return t[p].s;
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)+ask(rson,mid+1,r);
}
ll ask(int l,int r){return ask(root(r),l,r)*pw[l];}
V work(){
	for(int x,y,l;m--;cout<<ans[ask(x,x+l)==ask(y,y+l)])
		scanf("%d%d%d",&x,&y,&l),l--;
}
int main(){
	input();
	init();
	work();
	return 0;
}