#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct mat {
	int v[3][3],n,m;
	mat() {
		memset(v,0,sizeof(v));
		n=m=0;
	}
	mat operator *(const mat &a) const {
		mat b;
		b.n=n,b.m=a.m;
		for(int i=0; i<n; i++)
			for(int j=0; j<a.m; j++)
				for(int k=0; k<m; k++)
					b.v[i][j]=(b.v[i][j]+1ll*v[i][k]*a.v[k][j])%(mod-1);
		return b;
	}
} ans,tas;
inline int powmod(int a,long long b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline void Pow(long long n) {
	tas.v[0][2]=tas.v[1][0]=tas.v[1][2]=tas.v[2][1]=tas.v[2][2]=1;
	ans.v[0][0]=ans.v[1][1]=ans.v[2][2]=1;
	tas.n=tas.m=ans.n=ans.m=3;
	while(n) {
		if(n&1)ans=ans*tas;
		tas=tas*tas;
		n>>=1;
	}
	tas=ans;
	ans=mat();
}
int len,p[50];
inline void fj(int x) {
	for(int i=2;1ll*i*i<=x;i++) {
		if(x%i==0)p[++len]=i;
		while(x%i==0)x/=i;
	}
	if(x!=1)p[++len]=x;
}
inline int calc(int a,int b) {
	int cnt=0;
	while(a%b==0)cnt++,a/=b;
	return cnt;
}
int main() {
	long long n;
	int f1,f2,f3,c,Ans=1;
	cin>>n>>f1>>f2>>f3>>c;
	fj(f1),fj(f2),fj(f3),fj(c);
	Pow(n-1);
	sort(p+1,p+1+len);
	len=unique(p+1,p+1+len)-p-1;
	ans.n=1,ans.m=3;
	for(int i=1;i<=len;i++) {
		int t=calc(c,p[i]);
		ans.v[0][0]=calc(f1,p[i])+t;
		ans.v[0][1]=calc(f2,p[i])+2*t;
		ans.v[0][2]=calc(f3,p[i])+3*t;
		ans=ans*tas;
		Ans=1ll*Ans*powmod(p[i],ans.v[0][0])%mod;
	}
	printf("%lld\n",1ll*Ans*powmod(powmod(c,n),mod-2)%mod);
	return 0;
}