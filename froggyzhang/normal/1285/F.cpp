#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef unsigned long long ull;
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
int n,m,c[N],a[N],mu[N];
ll ans;
vector<int> fac[N];
ll Solve(int n){
	ll ans=0;
	static int t[N];
	for(int i=1;i<=n;++i)t[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i)t[i]+=a[j];
	}
	for(int r=n,l=1;l<=r;--r){
		if(!a[r])continue;
		static int h[N];
		int tot=0;
		for(auto k:fac[r]){
			tot+=t[k]*mu[k];
			h[k]=mu[k];
		}
		while(tot&&l<=r){
			if(!a[l]){++l;continue;}
			ans=max(ans,1LL*l*r);
			for(auto i:fac[l])--t[i],tot-=h[i];
			++l;
		}
		for(auto k:fac[r])h[k]=0,--t[k];
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		ans=max(ans,1LL*x);
		c[x]=1;
		m=max(m,x);
	}
	for(int i=1;i<=m;++i){
		for(int j=i;j<=m;j+=i){
			fac[j].push_back(i);
		}
	}
	mu[1]=1;
	for(int i=1;i<=m;++i){
		for(int j=i+i;j<=m;j+=i)mu[j]-=mu[i];
	}
	for(int d=1;d<=m;++d){
		for(int i=1;i<=m/d;++i)a[i]=c[i*d];
		ans=max(ans,Solve(m/d)*d);	
	}
	printf("%lld\n",ans);
	return 0;
}