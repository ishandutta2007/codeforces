#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int p1,p2;
ll t1,t2;
int h,s;
const int N=5011;
ll f[N];
ll g[N], g2[N];
__int128 calc1(ll m){
	return (__int128)m/t1 * (p1-s) + (__int128)m/t2*(p2-s);
}
__int128 calc2(ll m){
	return ((__int128)m-t1)/t1 * (p1-s) + (__int128)(m-t2)/t2*(p2-s);
}
ll solve(){
	if(t1>t2) swap(p1,p2), swap(t1,t2);
	memset(f,0x3f,sizeof(f));
	g[0]=0;
	for(int i=1;i<=h;++i) {
		ll l=t1,r=i*t1;
		while(l<r){
			ll m=(l+r)/2;
			if(calc1(m) >= i) r=m;
			else l=m+1;
		}
		g[i]=l;
		
	}
	ll ans=g[h];
	g2[0]=t2;
	for(int i=1;i<=h;++i) {
		ll l=t2,r=i*t1+t2;
		while(l<r){
			ll m=(l+r)/2;
			if(calc2(m) >= i) r=m;
			else l=m+1;
		}
		g2[i]=l;
	}
	f[0]=0;
	int w=p1+p2-s;
	if(w>=h) ans=min(ans, t2);
	dbg(ans);
	for(int i=1;i<=h;++i) {
		if(i<=w) f[i]=g2[0];
		f[i]=min(f[i], g[i]);
		for(int j=0;j+w<=i;++j) f[i]=min(f[i], f[i-j-w] + g2[j]);
	}
	ans=min(ans, f[h]);
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>p1>>t1>>p2>>t2>>h>>s) cout<<solve()<<"\n";
}