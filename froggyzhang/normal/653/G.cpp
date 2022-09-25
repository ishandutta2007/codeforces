#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int MX=1e6;
int n,a[N],ntp[N],ans,fac[N],ifac[N],pw2[N];
vector<pii> fc[N];
vector<int> cnt[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}	
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
int Solve(vector<int> &a){
	int all=accumulate(a.begin(),a.end(),0);
	a[0]=n-all;
	int m=a.size(),tot=0;
	for(int i=0,now=0;i<m;++i){
		now+=a[i];
		static int b[N],c[N];
		b[0]=pw2[now];
		for(int k=1;k<=min(now,n-now);++k){
			b[k]=(b[k-1]+mod-C(now,k-1))%mod;
		}
		for(int k=1;k<=min(now,n-now);++k){
			c[k]=(c[k-1]+1LL*C(now,k)*k)%mod;
		}
		for(int k=1;k<=n-now&&k<=now;++k){
			tot=(tot+1LL*C(n-now,k)*k%mod*b[k])%mod;
		}
		for(int k=1;k<=n-now;++k){
			tot=(tot+1LL*C(n-now,k)*c[min(k-1,now)])%mod;
		}
	}
	return tot;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=2;i<=MX;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=MX;j+=i)ntp[j]=1;
			for(int x=i;;x*=i){
				for(int j=x;j<=MX;j+=x){
					if(x==i)fc[j].emplace_back(i,0);
					++fc[j].back().second;
				}
				if(x>MX/i)break;
			}	
		}	
	}
	for(int i=1;i<=n;++i){
		for(auto [x,w]:fc[a[i]]){
			if(cnt[x].size()<=w)cnt[x].resize(w+1);
			++cnt[x][w];	
		}	
	}
	for(int i=2;i<=MX;++i){
		if(!cnt[i].empty()){
			ans=(ans+Solve(cnt[i]))%mod;	
		}	
	}
	cout<<ans<<'\n';
	return 0;
}