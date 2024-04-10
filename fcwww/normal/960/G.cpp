#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
typedef long long ll;
#define N 200050
#define mod 998244353
int qp(int x,int y) {
	int re=1; for(;y;y>>=1,x=ll(x)*x%mod) if(y&1) re=ll(re)*x%mod; return re;
}
int INV(int x) {return qp(x,mod-2);}
int ntt_w[2][N<<2];
int mem[N<<7],*ptr=mem;
void ntt_init(int len) {
	int j,k,t;
	for(k=2;k<=len;k<<=1) {
		t=k>>1;
		int w=1,wn=qp(3,(mod-1)/k);
		for(j=0;j<t;j++) {
			ntt_w[0][j+t]=w;
			w=ll(w)*wn%mod;
		}
		wn=INV(wn);w=1;
		for(j=0;j<t;j++) {
			ntt_w[1][j+t]=w;
			w=ll(w)*wn%mod;
		}
	}
}
// int mx=0;
void ntt(int *a,int len,int flg) {
	// mx=max(mx,len);
	int i,j,k,t,tmp,o=flg!=1;
	for(i=k=0;i<len;i++) {
		if(i>k) swap(a[i],a[k]);
		for(j=len>>1;(k^=j)<j;j>>=1) ;
	}
	for(k=2;k<=len;k<<=1) {
		t=k>>1;for(i=0;i<len;i+=k) {
			for(j=i;j<i+t;j++) {
				tmp=ll(a[j+t])*ntt_w[o][j-i+t]%mod;
				a[j+t]=(a[j]-tmp)%mod;
				a[j]=(a[j]+tmp)%mod;
			}
		}
	}
	if(flg==-1) for(tmp=INV(len),i=0;i<len;i++) a[i]=ll(a[i])*tmp%mod;
}
int A[N<<2],B[N<<2];
int n,_a,_b,lim;
struct swk {
	int *a,len;
	swk() {}
	swk(int l_) {len=l_,a=ptr,ptr+=len;}
	bool operator < (const swk &u) const {return len>u.len;}
	swk operator * (const swk &u) const {
		swk re(len+u.len-1);
		int i,j;
		if(re.len<=200) {
			for(i=0;i<len;i++) if(a[i]) for(j=0;j<u.len;j++) if(i+j<re.len) re.a[i+j]=(re.a[i+j]+ll(a[i])*u.a[j])%mod;
			return re;
		}
		int l=1;
		for(;l<len+u.len;l<<=1);
		memset(A,0,l<<2);
		memset(B,0,l<<2);
		memcpy(A,a,len<<2);
		memcpy(B,u.a,u.len<<2);
		ntt(A,l,1),ntt(B,l,1);
		for(i=0;i<l;i++) A[i]=ll(A[i])*B[i]%mod;
		ntt(A,l,-1);
		memcpy(re.a,A,re.len<<2);
		return re;
	}
};
priority_queue<swk>q;
ll fac[N],inv[N];
ll C(int x,int y) {
	if(x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main() {
	// scanf("%d%d%d",&n,&a,&b),printf("%lld\n",C[a+b-2][a-1]*st[n-1][a+b-2]%mod);
	scanf("%d%d%d",&n,&_a,&_b); n--;
	if(!n) {
		if(_a+_b==2) puts("1");
		else puts("0");
		return 0;
	}
	lim=max(n+2,_a+_b);
	int len=1,i;
	for(;len<=(lim<<1);len<<=1);
	ntt_init(len);

	for(i=0;i<n;i++) {
		swk aa(2); aa.a[0]=i; aa.a[1]=1;
		q.push(aa);
	}
	for(i=0;i<n-1;i++) {
		swk aa=q.top(); q.pop();
		swk bb=q.top(); q.pop();
		q.push(aa*bb);
	}
	swk ans=q.top();

	for(fac[0]=i=1;i<N;i++)fac[i]=fac[i-1]*i%mod; 
	inv[N-1]=qp(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;

	// printf("%lld\n",C(_a+_b-2,_a-1));

	// if((_a+_b)&1)ans.a[_a+_b-2]*=-1;

	printf("%lld\n",(C(_a+_b-2,_a-1)*ans.a[_a+_b-2]%mod+mod)%mod);

	return 0;
}