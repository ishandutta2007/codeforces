#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i<=b;i++)
const int N=1e5+1,K=800,mod=998244353;
const char ans[2][5]={"No\n","Yes\n"};
int n,m,q,tot;
int a[N],pw[N],inv[N];
struct node{
	int*s,len;
	node(){s=NULL,len=0;}
	I val(){return s[len];}
	I calc(int x){return 1ll*(s[len]-s[len-x]+mod)*inv[len-x]%mod;}
	I del(int v,int x){return calc(x)==v&&(len-=x,1);}
	I ins(int x){
		if(x>0)return s[len+1]=(1ll*x*pw[len]+s[len])%mod,++len;
		else return!len||calc(1)==-x&&len--;
	}
}sta[N];
I get(int l,int r,int d,node&out){
	static int p,tmp[4][K+1];
	if(out.s==NULL)out.s=tmp[p],p=p+1&3;
	for(out.len=0;l!=r+d;l+=d)if(!out.ins(a[l]*d))return 0;
	return 1;
}
I pop(node x){
	for(int len;tot&&x.len;x.len-=len){
		len=min(x.len,sta[tot].len);
		if(!sta[tot].del(x.calc(len),len))return 0;
		tot-=!sta[tot].len;
	}
	return!x.len;
}
V push(node x){if(x.len)sta[++tot]=x;}
struct block{
	int L,R,need,tag,f[K+1],g[K+1];
	node pre,nxt;
	V init(int l,int r){L=l,R=r,need=1,pre.s=f,nxt.s=g;}
	V build(){if(need)need=0,tag=get(R,L,-1,pre)&&get(L,R,1,nxt);}
	I solve(int l,int r){
		if(R<l||L>r)return 1;
		int out;node x,y;
		l=max(L,l),r=min(R,r);
		if(L==l&&r==R)build(),x=pre,y=nxt,out=tag;
		else out=get(r,l,-1,x)&&get(l,r,1,y);
		return out&&pop(x)&&(push(y),1);
	}
}t[N/K+1];
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%d",a+i);
}
V init(){
	pw[0]=inv[0]=1,pw[1]=19260817,inv[1]=494863259,m=0;
	FOR(i,2,n)pw[i]=1ll*pw[i-1]*pw[1]%mod,inv[i]=1ll*inv[i-1]*inv[1]%mod;
	for(int l=1,r;l<=n;l=r+1)r=min(n,l+K-1),t[++m].init(l,r);
}
I ask(int l,int r){
	if(tot=0,r-l+1&1)return 0;
	FOR(i,1,m)if(!t[i].solve(l,r))return 0;
	return!tot;
}
V work(){
	scanf("%d",&q);
	for(int opt,x,y;q--;){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)a[x]=y,t[(x-1)/K+1].need=1;
		else cout<<ans[ask(x,y)];
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}