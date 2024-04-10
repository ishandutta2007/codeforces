#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1<<19,mod=998244353;
char st[N];
int n,m,a[N],b[N],c[N],val[N];
int lmt,l,w[N],r[N],p[N],q[N],t[N];
V input(){
	FOR(i,1,26)scanf("%d",p+i);
	scanf("%s",st+1),m=strlen(st+1);
	FOR(i,1,m)b[m-i]=st[i]-'a'+1;
	scanf("%s",st+1),n=strlen(st+1);
	FOR(i,1,n)a[i]=st[i]-'a'+1;
}
I Pow(ll t,int x){
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
I o(){
	static mt19937 seed(time(0));
	return abs((int)seed());
}
V init(){
	for(lmt=1,l=-1;lmt<=n+m+1;lmt<<=1)l++;
	FOR(i,1,lmt-1)r[i]=r[i>>1]>>1|(i&1)<<l;
	int wn=Pow(3,mod>>++l);w[lmt>>1]=1;
	FOR(i,lmt/2+1,lmt-1)w[i]=1ll*w[i-1]*wn%mod;
	ROF(i,lmt/2-1,1)w[i]=w[i<<1];
	FOR(i,0,m-1)c[i]=p[b[i]];
	FOR(i,1,26)val[i]=o()%mod;
	FOR(i,1,n)a[i]=val[a[i]];
	FOR(i,0,m-1)b[i]=val[b[i]],c[i]=val[c[i]];
}
V DFT(int*a){
	static unsigned long long int tmp[N];
	FOR(i,0,lmt-1)tmp[i]=a[r[i]];
	for(int i=1,x;i<lmt;i<<=1)for(int j=0,d=i<<1;j<lmt;j+=d)FOR(k,0,i-1)
		x=tmp[i|j|k]*w[i|k]%mod,tmp[i|j|k]=tmp[j|k]+mod-x,tmp[j|k]+=x;
	FOR(i,0,lmt-1)a[i]=tmp[i]%mod;
}
V IDFT(int*a){
	reverse(a+1,a+lmt),DFT(a);
	int bk(mod-mod/l);
	FOR(i,0,lmt-1)a[i]=1ll*a[i]*bk%mod;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
V add(int*p,int*q,int*t){FOR(i,0,lmt-1)check(t[i]+=1ll*p[i]*q[i]%mod);}
V work(){
	FOR(i,0,lmt-1)p[i]=Pow(a[i],4),q[i]=i<m;
	DFT(p),DFT(q),add(p,q,t);
	FOR(i,0,lmt-1)p[i]=mod-2ll*Pow(a[i],3)%mod,check(q[i]=b[i]+c[i]);
	DFT(p),DFT(q),add(p,q,t);
	FOR(i,0,lmt-1)p[i]=1ll*a[i]*a[i]%mod,q[i]=(2ll*b[i]*c[i]+Pow(b[i]+c[i],2))%mod;
	DFT(p),DFT(q),add(p,q,t);
	FOR(i,0,lmt-1)p[i]=mod-2ll*a[i]%mod,q[i]=1ll*b[i]*c[i]%mod*(b[i]+c[i])%mod;
	DFT(p),DFT(q),add(p,q,t);
	FOR(i,0,lmt-1)p[i]=1<=i&&i<=n,q[i]=1ll*Pow(b[i],2)*Pow(c[i],2)%mod;
	DFT(p),DFT(q),add(p,q,t),IDFT(t);
	FOR(i,m,n)cout<<!t[i];
}
int main(){
	input();
	init();
	work();
	return 0;
}