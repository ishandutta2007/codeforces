#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
const int N=1e5+50;
int a[N];
int f[N],g[N];
int s[N],t[N];;
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	ll r=0;
	FOR(i,1,n) s[i]=0;
	FOR(i,1,n) {
		FOR(j,1,n) t[j]=t[j-1]+s[j];
		int c=0;
		DOR(j,n,i+1) {
			r+=t[a[j]]*c;
			if(a[j]<a[i]) ++c;
		}
		s[a[i]]++;
	}
	printf("%lld\n",r);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}