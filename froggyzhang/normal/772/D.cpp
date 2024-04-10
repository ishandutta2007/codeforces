#include<bits/stdc++.h>
using namespace std;
#define N 1000000
typedef long long ll;
const int mod=1e9+7;
int n,pw10[10],g[N];
struct Data{
	int t0,t1,t2;
	Data(){t0=1;}
	Data(int _0,int _1,int _2):t0(_0),t1(_1),t2(_2){}
	Data(int _x):t0(2),t1(_x),t2(1LL*_x*_x%mod){};
	friend Data operator + (const Data &a,const Data &b){
		return Data(1LL*a.t0*b.t0%mod,(1LL*a.t0*b.t1+1LL*a.t1*b.t0)%mod,(1LL*a.t0*b.t2+2LL*a.t1*b.t1+1LL*a.t2*b.t0)%mod);
	}
}f[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		f[x]=f[x]+Data(x);
	}
	pw10[0]=1;
	for(int i=1;i<=6;++i)pw10[i]=pw10[i-1]*10;
	ll ans=0;
	for(int j=0;j<6;++j){
		for(int i=0;i<N;++i){
			if(i/pw10[j]%10==0){
				for(int k=8;k>=0;--k){
					f[i+k*pw10[j]]=f[i+k*pw10[j]]+f[i+(k+1)*pw10[j]];
				}
			}
		}
	}
	for(int i=0;i<N;++i)g[i]=f[i].t2;
	for(int j=0;j<6;++j){
		for(int i=0;i<N;++i){
			if(i/pw10[j]%10==0){
				for(int k=0;k<9;++k){
					g[i+k*pw10[j]]=(g[i+k*pw10[j]]-g[i+(k+1)*pw10[j]]+mod)%mod;
				}
			}
		}
	}
	for(int i=0;i<N;++i){
		ans^=1LL*i*g[i];
	}
	cout<<ans<<'\n';
	return 0;
}