#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int mod=1e9+7;
const ll mod2=1LL*mod*mod;
ll P;
int n,m,b[N];
int Len;
struct Matrix{
	int g[N][N];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix _b;
		for(int i=0;i<Len;++i)
			for(int j=0;j<Len;++j)
				_b.g[i][j]=b.g[j][i];
		Matrix c;
		for(int i=0;i<Len;++i){
			for(int j=0;j<Len;++j){
				ll tmp=0;
				for(int k=0;k<Len;++k){
					tmp+=1LL*a.g[i][k]*_b.g[j][k];
					tmp=(tmp>=mod2?tmp-mod2:tmp);
				}
				c.g[i][j]=tmp%mod;
			}
		}
		return c;
	}
}A[62],e;
struct Vector{
	int g[N];
	Vector(){memset(g,0,sizeof(g));}
	friend Vector operator * (const Vector &a,const Matrix &b){
		Vector c;
		for(int i=0;i<Len;++i){
			for(int j=0;j<Len;++j){
				c.g[i]=(c.g[i]+1LL*a.g[j]*b.g[j][i])%mod;
			}
		}
		return c;
	}
};
Matrix init(int c){
	Matrix a;
	for(int i=0;i<=n;++i){
		a.g[i][i]=1;
		a.g[i][c]=1;
	}
	return a;
}
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int Get(ll x){
	int zz=0;
	for(int i=0;x;++i){
		zz=(zz+b[i]*(x%n))%n;
		x/=n;
	}
	return zz;
}
Matrix Shit(const Matrix &a,int k){
	Matrix b;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			b.g[i==n?n:(i+k)%n][j==n?n:(j+k)%n]=a.g[i][j];
		}
	}
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>P>>n;
	Len=n+1;
	for(int i=0;i<Len;++i)e.g[i][i]=1;
	for(int i=0;i<60;++i){
		b[i]=1;
	}
	A[0]=init(0);
	vector<int> dig;
	while(P)dig.push_back(P%n),P/=n;
	int lg=0;
	while((1<<lg)<=n)++lg;
	for(int i=1;i<(int)dig.size();++i){
		A[i]=A[i-1];
		int now=1;
		for(int j=lg-2;j>=0;--j){
			A[i]=A[i]*Shit(A[i],now*b[i-1]%n);
			now<<=1;
			if(n>>j&1){
				A[i]=A[i]*Shit(A[i-1],now*b[i-1]%n);
				++now;
			}
		}
	}
	Vector ans;
	ans.g[n]=1;
	int now=0;
	for(int i=(int)dig.size()-1;i>=0;--i){
		for(int k=0;k<dig[i];++k){
			ans=ans*Shit(A[i],(b[i]*k+now)%n);
		}
		now=(now+dig[i]*b[i])%n;
	}
	int Ans=0;
	for(int i=0;i<Len;++i){
		Ans=(Ans+ans.g[i])%mod;
	}
	cout<<Ans<<'\n';
	return 0;
}