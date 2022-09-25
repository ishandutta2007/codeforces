#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int n,X;
namespace Poly{
	#define N 536666
	const double PI=acos(-1.0);
	struct Complex{
		double x,y;
		Complex(double _x=0,double _y=0){x=_x,y=_y;}
		friend Complex operator + (const Complex &a,const Complex &b){
			return Complex(a.x+b.x,a.y+b.y);
		}
		friend Complex operator - (const Complex &a,const Complex &b){
			return Complex(a.x-b.x,a.y-b.y);
		}
		friend Complex operator * (const Complex &a,const Complex &b){
			return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
		}
	};
	typedef vector<Complex> poly;
	vector<Complex> GG[2][20];
	void Init(int t){
		for(int p=1;p<=t;++p){
			Complex buf1(cos(2*PI/(1<<p)),sin(2*PI/(1<<p)));
			Complex buf0(cos(2*PI/(1<<p)),-sin(2*PI/(1<<p)));
			GG[0][p].resize(1<<p);
			GG[1][p].resize(1<<p);
			GG[0][p][0]=GG[1][p][0]=Complex(1,0);
			for(int i=1;i<(1<<p);++i){
				GG[0][p][i]=GG[0][p][i-1]*buf0;
				GG[1][p][i]=GG[1][p][i-1]*buf1;
			}
		}
	}
	int tr[N];
	int FFT_init(int n){
		int lim=1;
		while(lim<n)lim<<=1;
		for(int i=0;i<lim;++i){
			tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
		}
		return lim;
	}
	void FFT(poly &f,int flag,int n){
		f.resize(n);
		for(int i=0;i<n;++i){
			if(i<tr[i])swap(f[i],f[tr[i]]);
		}
		for(int p=2,j=1;p<=n;p<<=1,++j){
			int len=p>>1;
			for(int k=0;k<n;k+=p){
				auto buf=GG[flag][j].begin();
				for(int i=k;i<k+len;++i,++buf){
					Complex tmp=(*buf)*f[i+len];
					f[i+len]=f[i]-tmp;
					f[i]=f[i]+tmp;	
				}
			}	
		}
		if(!flag){
			for(int i=0;i<n;++i){
				f[i].x=f[i].x/n;
			}	
		}
	}
	poly Mul(poly A,poly B){
		int n=A.size()+B.size()-1;
		int lim=FFT_init(n);
		poly C(lim);
		FFT(A,1,lim),FFT(B,1,lim);
		for(int i=0;i<lim;++i){
			C[i]=A[i]*B[i];
		}
		FFT(C,0,lim);
		C.resize(n);
		return C;
	}
};
using Poly::poly;
poly A;
ll ans0;
int main(){
	Poly::Init(19);
	n=read(),X=read();
	A.resize(n+1);
	++A[0].x;
	for(int i=1,now=0,qwq=1;i<=n;++i){
		int t=read();
		if(t<X)++now,qwq=1;
		else ans0+=qwq++;
		++A[now].x;
	}
	auto B=A;
	reverse(B.begin(),B.end());
	A=Mul(A,B);
	printf("%lld ",ans0);
	for(int i=n+1;i<=2*n;++i){
		printf("%lld ",(ll)round(A[i].x));
	}
	return 0;
}