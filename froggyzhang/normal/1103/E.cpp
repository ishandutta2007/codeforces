#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int P=10;
const ull mod=(1LL<<58);
const ull inv3125=6723469279985657373ULL;
int m;
const int n=100000;
const int pw10[6]={1,10,100,1000,10000,100000};
struct Complex{
	ull g[P];
	Complex(int _x=0){memset(g,0,sizeof(g));g[0]=_x;}
	friend Complex operator + (const Complex &a,const Complex &b){
		Complex c;
		for(int i=0;i<P;++i){
			c.g[i]=a.g[i]+b.g[i];	
		}
		return c;
	}
	friend Complex operator - (const Complex &a,const Complex &b){
		Complex c;
		for(int i=0;i<P;++i){
			c.g[i]=a.g[i]-b.g[i];	
		}
		return c;
	}
	friend Complex operator * (const Complex &a,const Complex &b){
		Complex c;
		for(int i=0;i<P;++i){
			for(int j=0;j<P;++j){
				c.g[(i+j)%P]+=a.g[i]*b.g[j];
			}
		}
		return c;
	}
	friend Complex operator * (const Complex &a,const ull k){
		Complex c;
		for(int i=0;i<P;++i){
			c.g[i]=a.g[i]*k;
		}
		return c;
	}
	friend Complex operator += (Complex &a,const Complex &b){
		a=a+b;
		return a;
	}
}_w[P];
typedef vector<Complex> poly;
void init(){
	_w[0].g[0]=1;
	_w[1].g[1]=1;
	for(int i=2;i<P;++i){
		_w[i]=_w[i-1]*_w[1];	
	}
}
Complex qpow(Complex a,int b){
	Complex ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
void DWT(poly &f,int n,int flag){
	for(int d=0;d<5;++d){
		for(int i=0;i<n;++i){
			if(i/pw10[d]%P)continue;
			static Complex tmp[P];
			for(int j=0;j<P;++j)tmp[j]=0;
			for(int j=0;j<P;++j){
				for(int k=0;k<P;++k){
					tmp[j]+=f[i+pw10[d]*k]*_w[flag?j*k%P:(P-j)*k%P];	
				}
			}
			for(int j=0;j<P;++j){
				f[i+pw10[d]*j]=tmp[j];
			}
		}
	}
	if(!flag){
		for(int i=0;i<n;++i){
			f[i]=f[i]*inv3125;
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	poly A(n);
	cin>>m;
	for(int i=1,x;i<=m;++i){
		cin>>x;
		++A[x].g[0];
	}
	DWT(A,n,1);
	for(int i=0;i<n;++i){
		A[i]=qpow(A[i],m);	
	}
	DWT(A,n,0);
	for(int i=0;i<m;++i){
		for(int j=P-1;j>=4;--j){
			for(int k=4;k>=0;--k){
				if(k&1)A[i].g[j-k]+=A[i].g[j];
				else A[i].g[j-k]-=A[i].g[j];
			}
		}
		cout<<(A[i].g[0]>>5)%mod<<' ';
	}
	cout<<'\n';
	return 0;
}