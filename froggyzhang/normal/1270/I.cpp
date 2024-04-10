#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> poly;
typedef vector<poly> poly_2d;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,a[100],b[100];
poly_2d Mul(poly_2d A,poly_2d B){
	int n=A.size(),m=A[0].size();
	poly_2d C(n,poly(m));
	for(int i2=0;i2<n;++i2){
		for(int j2=0;j2<m;++j2){
			if(!B[i2][j2])continue;
			for(int i1=0;i1<n;++i1){
				for(int j1=0;j1<m;++j1){
					C[(i1+i2)%n][(j1+j2)%m]^=A[i1][j1];
				}
			}	
		}
	}
	return C;
}
int main(){
	n=read();
	poly_2d A(1<<n,poly(1<<n));
	poly_2d C=A;
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<(1<<n);++j){
			A[i][j]=read();
		}
	}
	C=A;
	int t=read();
	for(int i=0;i<t;++i)a[i]=read(),b[i]=read();
	for(int i=0,pw2=1;i<n;++i,pw2<<=1){
		poly_2d F(1<<n,poly(1<<n));
		for(int j=0;j<t;++j){
			F[a[j]*pw2%(1<<n)][b[j]*pw2%(1<<n)]^=1;
		}
		C=Mul(C,F);
	}
	int ans=0;
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<(1<<n);++j){
			ans+=C[i][j]!=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}