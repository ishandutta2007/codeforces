#include<bits/stdc++.h>
using namespace std;
const int N=110,M=1e6+10,mod=1e9+7;
int w[M],b[M],t[N];
struct mat {
	int n,m,v[N][N];
	mat() {
		memset(v,n=m=0,sizeof(v));
	}
	mat operator*(const mat &a)const {
		mat b;
		b.n=n;
		b.m=a.m;
		for(int i=0;i<b.n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<m;k++)
					b.v[i][j]=(b.v[i][j]+1ll*v[i][k]*a.v[k][j])%mod;
		return b;
	}
}ans,tas;
int main() {
	int n,l,m,a;
	scanf("%d%d%d",&n,&l,&m);
	ans.n=1,ans.m=tas.n=tas.m=m;
	for(int i=1;i<=n;i++)scanf("%d",&a),ans.v[0][a%m]++;
	for(int i=1;i<=n;i++)scanf("%d",w+i),t[w[i]%m]++;
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			tas.v[i][(i+j)%m]=t[j];
	l-=2;
	while(l) {
		if(l&1)ans=ans*tas;
		tas=tas*tas;
		l>>=1;
	}
	int Ans=0;
	for(int i=1;i<=n;i++)
		Ans=(Ans+ans.v[0][(2*m-b[i]-w[i])%m])%mod;
	printf("%d\n",Ans);
	return 0;
}