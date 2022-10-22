#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1e6+50;
const int Mod=1e9+7;
map<ll,int> a;
void solve() {
	a.clear();
	int n,K;
	scanf("%d%d",&n,&K);
	FOR(i,1,n) {
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int r=0;
	for(auto &e: a) {
		if(e.se) {
			ll y=e.fi*K;
			if(a.count(y)) {
				int w=min(e.se,a[y]);
				a[y]-=w;
				r+=e.se-w;
			} else {
				r+=e.se;
			}
		}
	}
	printf("%d\n",r);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}