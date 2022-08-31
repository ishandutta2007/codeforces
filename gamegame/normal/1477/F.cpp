#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int T=7001;
const int N=701;
ll n,k,t;
ll l[N];
vector<ll>poly[N];
ll f[T];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll roots[1<<22];
int rev[1<<22];
void fft(vector<ll>&p){
	int n=p.size();
	roots[0]=1;
	roots[1]=pw(15311432,(1<<23)/n);
	for(int i=2; i<n ;i++) roots[i]=roots[i-1]*roots[1]%mod;
	for(int i=1; i<n ;i++){
		rev[i]=rev[i/2]/2+((i&1)*n/2);
		if(i<rev[i]) swap(p[i],p[rev[i]]);
	}
	for(int k=1; k<n ;k*=2){
        for(int i=0; i<n ;i+=2*k){
            int cur=0,step=n/(2*k);
            for(int j=0; j<k;j++,cur+=step){
                ll x=p[i+j];
                ll y=p[i+j+k]*roots[cur]%mod;
                p[i+j]=(x+y>=mod?x+y-mod:x+y);
				p[i+j+k]=(x>=y?x-y:x+mod-y);
            }
        }
    }
}
vector<ll>multiply(vector<ll>x,vector<ll>y){
	int n=1;
	while(n<x.size()+y.size()) n*=2;
	x.resize(n,0);y.resize(n,0);
	fft(x);fft(y);
	for(int i=0; i<n ;i++) x[i]=x[i]*y[i]%mod;
	reverse(x.begin()+1,x.end());
	fft(x);
	ll inv=pw(n,mod-2);
	for(int i=0; i<n ;i++) x[i]=x[i]*inv%mod;
	while(x.back()==0) x.pop_back();
	return x;
}
vector<ll>multiply2(vector<ll>x,vector<ll>y){
	vector<ll>z;z.resize(x.size()+y.size()-1);
	for(auto c:z) c=0;
	for(int i=0; i<x.size() ;i++){
		for(int j=0; j<y.size() ;j++){
			z[i+j]=(z[i+j]+x[i]*y[j])%mod;	
		}
	}
	return z;
}
vector<ll>solve(int l,int r){
	if(l==r) return poly[l];
	int mid=(l+r)/2;
	return multiply(solve(l,mid),solve(mid+1,r));
}
vector<ll>solve2(int l,int r){
	if(l==r) return poly[l];
	int mid=(l+r)/2;
	return multiply2(solve(l,mid),solve(mid+1,r));
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> l[i];
		t=t+l[i];
	}
	f[0]=1;
	for(int i=1; i<=t ;i++) f[i]=f[i-1]*i%mod;
	for(int i=1; i<=n ;i++){
		poly[i].resize(l[i]*(n+1)+2);
		for(int j=0; j<=l[i] ;j++){
			for(int y=0; y<=1 ;y++){
				if((j+y)*k>=l[i]) continue;
				int d=j*(n+1)+y;
				poly[i][d]=pw((l[i]-(j+y)*k)*pw(t,mod-2)%mod,j)*pw(f[j],mod-2)%mod;
				if((j+y)%2==1) poly[i][d]=(mod-poly[i][d])%mod;
			}
		}
		while(poly[i].back()==0) poly[i].pop_back();
	}
	auto e=solve(1,n);
	ll ans=0;
	for(int i=0; i<e.size() ;i++){
		if(i==0) continue;
		int sj=i/(n+1);
		int sy=i%(n+1);
		if((sj+sy)*k>=t) continue;
		ll cur=f[sj]*pw(t*pw((sj+sy)*k,mod-2)%mod,sj+1)%mod;
		ans=(ans+cur*e[i])%mod;
	}
	ans=(mod-ans)%mod;
	cout << ans << '\n';
}