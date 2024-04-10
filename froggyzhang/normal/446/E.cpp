#include<bits/stdc++.h>
using namespace std;
const int mod=1051131;
const int phi=700752;
const int inv2=525566;
#define N 26
typedef long long ll;
int n,m,X,Y,b[N];
ll D;
vector<int> A,B;
inline void Plus(int &x,int y){
	(x+=y)>=mod?x-=mod:x;
}
inline int ck(int x){
	return x>=mod?x-mod:x;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void FWT(vector<int> &a,int n,int op){n=1<<n;for(int mid=1;mid<n;mid<<=1)for(int j=0;j<n;j+=(mid<<1))for(int k=0;k<mid;++k){int x=a[j+k],y=a[j+k+mid];(a[j+k]=(x+y))>=mod&&(a[j+k]-=mod),(a[j+k+mid]=x+mod-y)>=mod&&(a[j+k+mid]-=mod);}if(op<0){int inv=qpow(inv2,__lg(n));for(int i=0;i<n;++i)a[i]=1LL*a[i]*inv%mod;}}
int main(){
	cin>>n>>D>>m;
	X=101,Y=10007;
	b[0]=1;
	for(int i=1;i<=n;++i){
		b[i]=((1<<i)-(1<<~-i))%mod;
	}
	A.resize(1<<n),B.resize(1<<n);
	for(int i=0;i<m;++i){
		cin>>A[i];
	}
	for(int i=m;i<1<<n;++i){
		A[i]=(1LL*A[i-m]*X+Y)%mod;
	}
	B[0]=1;
	for(int i=1;i<n;++i){
		Plus(b[i],b[i-1]);
	}
	for(int i=1;i<(1<<n);++i){
		Plus(B[i],b[__lg(i&(-i))]);
	}
	FWT(A,n,1),FWT(B,n,1);
	D=D>=phi?D%phi+phi:D;
	for(int i=0,pw=-1;i<(1<<n);++i){
		if(!i||B[i]^B[i-1]){
			pw=qpow(B[i],D);
		}
		A[i]=1LL*A[i]*pw%mod;
	}
	FWT(A,n,-1);
	int Ans=0;
	for(int i=0;i<(1<<n);++i){
		Ans^=A[i];
	}
	cout<<Ans<<'\n';
	//cerr<<" time: "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}