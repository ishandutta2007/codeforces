#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct mat {
	int v[110][110],n,m;
	mat() {
		memset(v,n=m=0,sizeof(v));
	}
	mat operator*(const mat &a)const {
		mat b;
		b.n=n;
		b.m=a.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<a.m;k++)
					b.v[i][k]=(b.v[i][k]+1ll*v[i][j]*a.v[j][k])%(mod-1);
		return b;
	}
}tas,f;
unordered_map<int,int>S;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int BSGS(int a,int b) {
	int B=sqrt(mod),P=1;
	for(int i=0;i<B;i++) {
		S[P]=i;
		P=1ll*P*a%mod;
	}
	P=qpow(P,mod-2);
	for(int i=0;i<=B;i++) {
		if(S.count(b))return S[b]+i*B;
		b=1ll*b*P%mod;
	}
	return -1;
}
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x=1,y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y=y-a/b*x;
	return t;
}
signed main() {
	int k,n,m;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&tas.v[k-i][k-1]);
	f.n=1,f.m=tas.n=tas.m=k;
	for(int i=0;i<k-1;i++)
		tas.v[i+1][i]=1;
	f.v[0][k-1]=1;
	scanf("%d%d",&n,&m);
	n-=k;
	while(n) {
		if(n&1)f=f*tas;
		tas=tas*tas;
		n>>=1;
	}
	int a=f.v[0][k-1],y=BSGS(3,m);
	int X,Y;
	int g=exgcd(a,mod-1,X,Y);
	X=(X%(mod-1)+mod-1)%(mod-1);
	if(y%g)puts("-1");
	else {
		int b=1ll*y/g*X%(mod-1);
		printf("%d\n",qpow(3,b));
	}
	return 0;
}