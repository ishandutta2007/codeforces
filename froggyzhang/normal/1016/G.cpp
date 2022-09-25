#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef vector<ll> poly;
int n;
ll X,Y,a[N],fac[N],m;
inline int sdiv(ll x,ll p){
	int cnt=0;
	while(x%p==0)x/=p,++cnt;
	return cnt;	
}
void Split(ll x){
	for(int i=2;i<=1000000;++i){
		if(x%i==0){
			fac[m++]=i;
			while(x%i==0)x/=i;	
		}
	}
	if(x>1){
		ll tp=sqrt(x);
		while(1LL*(tp+1)*(tp+1)<=x);
		if(tp*tp==x)fac[m++]=tp;
		else{
			for(int i=1;i<=n;++i){
				ll emm=__gcd(a[i],x);
				if(emm>1&&emm<x){
					fac[m++]=emm,fac[m++]=x/emm;
					x=1;	
				}
			}
			if(x>1)fac[m++]=x;
		}
	}
}
void FWT_AND(poly &f,int x){
	for(int p=2;p<=(1<<m);p<<=1){
		int len=p>>1;
		for(int k=0;k<(1<<m);k+=p){
			for(int i=k;i<k+len;++i){
				f[i]+=x*f[i+len];
			}
		}	
	}
}
poly AND(poly A,poly B){
	FWT_AND(A,1);
	FWT_AND(B,1);
	for(int i=0;i<(1<<m);++i){
		A[i]=A[i]*B[i];
	}
	FWT_AND(A,-1);
	return A;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>X>>Y;
	if(Y%X){
		cout<<0<<'\n';return 0;
	}
	for(int i=1;i<=n;++i)cin>>a[i];
	Split(Y/X);
	poly A(1<<m),B(1<<m);
	for(int i=1;i<=n;++i){
		if(a[i]%X==0){
			int st=0;
			for(int j=0;j<m;++j){
				if(sdiv(a[i],fac[j])^sdiv(X,fac[j]))st|=1<<j;		
			}
			++A[st];
		}
		if(Y%a[i]==0){
			int st=0;
			for(int j=0;j<m;++j){
				if(sdiv(a[i],fac[j])^sdiv(Y,fac[j]))st|=1<<j;
			}
			++B[st];
		}
	}
	A=AND(A,B);
	cout<<A[0]<<'\n';
	return 0;
}