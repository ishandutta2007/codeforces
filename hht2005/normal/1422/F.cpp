#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=1e9+7;
stack<int>w[maxn],p[maxn];
int rt[maxn],ls[maxn*110],rs[maxn*110],val[maxn*110],f[maxn],Las,n,tot;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void add(int &np,int lp,int l,int r,int x) {
	np=++tot;
	if(lp)val[np]=val[lp];
	else val[np]=1;
	ls[np]=ls[lp];
	rs[np]=rs[lp];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(ls[np],ls[lp],l,mid,x);
	else add(rs[np],rs[lp],mid+1,r,x);
}
void mul(int &p,int l,int r,int x,int y,int v) {
	if(p<=Las) {
		tot++;
		ls[tot]=ls[p];
		rs[tot]=rs[p];
		val[tot]=val[p];
		p=tot;
	}
	if(x<=l&&r<=y) {
		val[p]=1ll*val[p]*v%mod;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)mul(ls[p],l,mid,x,y,v);
	if(y>mid)mul(rs[p],mid+1,r,x,y,v);
}
void mul(int x,int v,int cnt) {
	int las=0;
	while(w[v].top()<=cnt) {
		mul(rt[x],1,n,p[v].top()+1,x,qpow(v,w[v].top()-las));
		las=w[v].top();
		w[v].pop();
		p[v].pop();
	}
	mul(rt[x],1,n,p[v].top()+1,x,qpow(v,cnt-las));
	p[v].push(x);
	w[v].push(cnt);
}
int qry(int p,int l,int r,int x) {
	if(!p)return 1;
	if(l==r)return val[p];
	int mid=(l+r)>>1,mul=val[p];
	if(x<=mid)mul=1ll*mul*qry(ls[p],l,mid,x)%mod;
	else mul=1ll*mul*qry(rs[p],mid+1,r,x)%mod;
	return mul;
}
int main() {
	for(int i=2;i<maxn;i++) 
		if(!f[i]) {
			p[i].push(0);
			w[i].push(1e9);
			for(int j=i;j<maxn/i;j++)
				f[i*j]=1;
		}
	scanf("%d",&n);
	int q,l,r,las=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&l);
		add(rt[i],rt[i-1],1,n,i);
		for(int j=2;j*j<=l;j++) {
			int cnt=0;
			while(l%j==0) {
				l/=j;
				cnt++;
			}
			if(cnt)mul(i,j,cnt);
		}
		if(l!=1)mul(i,l,1);
		Las=tot;
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&l,&r);
		l=(l+las)%n+1;
		r=(r+las)%n+1;
		if(l>r)swap(l,r);
		printf("%d\n",las=qry(rt[r],1,n,l));
	}
	return 0;
}