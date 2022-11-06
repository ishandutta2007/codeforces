#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=1e9+7;
const int iv2=(mo+1)/2;
int Pow(int a,int b,int p=mo){
	int r=1;
	for(;b;b>>=1,a=1LL*a*a%p)
		if(b&1)r=1LL*r*a%p;
	return r;
}
const int N=1e6+11;
int p2[N],p2v[N];

int f[N];
int g[N];
void solve(){
	int n;
	cin>>n;
	int m=n/2+1;
	g[n+1]=0;
	for(int i=n;i>=1;--i) {
		if(i==n) {
			f[i]=p2v[(i+1)/2-1];
		}else{
			int t=1LL*p2v[(i+1)/2-1] * iv2%mo;
			if(i>=m){
				f[i]=t;
			}else{
				f[i]=1LL*t*(1+mo-g[2*i])%mo;
			}
		}
		g[i]=(f[i]+g[i+1])%mo;
	}
	//dbg(sum);
	for(int i=1;i<=n;++i)cout<<f[i]<<"\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	p2[0]=1;
	For(i,1,N)p2[i]=2*p2[i-1]%mo;
	p2v[N-1]=Pow(p2[N-1],mo-2);
	for(int i=N-1;i>=1;--i) p2v[i-1]=2*p2v[i]%mo;

	int t;
	cin>>t;
	while(t--){
		solve();
	}

}