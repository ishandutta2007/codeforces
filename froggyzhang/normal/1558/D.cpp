#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
const int mod=998244353;
const int mx=400000;
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
int T,n,m,fac[N],ifac[N];
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
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
class BIT{
public:
	int b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=mx)b[x]+=d,x+=lowbit(x);
	}
	inline int Find(int k){
		int ans=0;
		for(int i=18;i>=0;--i){
			if(ans+(1<<i)<=mx&&b[ans+(1<<i)]<k){
				ans+=1<<i;
				k-=b[ans];	
			}
		}
		return ans+1;
	}
}B;
pair<int,int> a[N],b[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		a[i].first=read();
		a[i].second=read();
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;--i){
		int x=B.Find(a[i].second);
		b[i]=make_pair(x,a[i].first);
		B.Add(x,-1);
	}
	for(int i=1;i<=m;++i){
		B.Add(b[i].first,1);
	}
	for(int i=1;i<=m;++i){
		B.Add(a[i].first,-1);
	}
	sort(b+1,b+m+1);
	int gg=n+n-1;
	for(int i=1;i<=m;++i){
		if(i<m&&b[i].first+1==b[i+1].first){
			gg-=b[i].second>b[i+1].second;
		}
		else{
			gg-=b[i].second>B.Find(b[i].first-i);
		}
	}
	printf("%d\n",C(gg,n));
	for(int i=1;i<=m;++i){
		B.Add(a[i].first,1);
	}
}
int main(){
	init(mx);
	for(int i=1;i<=mx;++i){
		B.Add(i,1);
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}