#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=998244353;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
const int N=1e6+50;

int a[N];
void solve() {
	int n,K;
	scanf("%d%d",&n,&K);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,n-K+1,n) {
		if(a[i]!=0 && a[i]!=-1) {
			puts("0");
			return ;
		}
	}
//	cerr << " -- " << endl;
	ll t=1;
	FOR(i,1,n-K) {
		if(a[i]==-1) {
			t=t*(i-1+K+1)%Mod;
		} else if(a[i]==0) {
			t=t*(K+1)%Mod;
		}
	}
	FOR(i,1,K) {
		t=t*i%Mod;
	}
	printf("%lld\n",t);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}