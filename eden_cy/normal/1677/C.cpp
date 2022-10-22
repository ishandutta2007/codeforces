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
const int N=1e6+50;
int a[N],b[N];
int nxt[N];
int vis[N];
int w[N],u[N];
void solve() {
	int n,m=0;
	scanf("%d",&n);
	FOR(i,1,n) vis[i]=0;
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) scanf("%d",&b[i]);
	FOR(i,1,n) nxt[a[i]]=b[i];
	FOR(i,1,n) if(!vis[i]) {
		int x=i;
		int c=0;
		while(true) {
			vis[x]=1;
			++c;
			if(nxt[x]==i) break;
			x=nxt[x];
		}
		w[++m]=c;
	}
	sort(w+1,w+m+1);
	int l=1,r=n;
	ll res=0;
	FOR(i,1,m) {
		int K=w[i]-w[i]%2;
		if(!K) continue;
		int e=0;
		FOR(j,0,K-1) {
			if(e==0) u[j]=l++;
			else u[j]=r--;
			e^=1;
		}
		FOR(j,0,K-1) res+=abs(u[j]-u[(j+1)%K]);
	}
	printf("%lld\n",res);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}