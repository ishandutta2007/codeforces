#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=2e5+50;

int a[N];
pii b[N];
int c[N];
void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) b[i]=make_pair(-a[i]-i,i);
	sort(b+1,b+n+1);
	FOR(i,1,m) a[b[i].se]=0;
	int c=0;
	ll r=0;
	FOR(i,1,n) {
		if(a[i]==0) ++c;
		else r+=c+a[i];
	}
	printf("%lld\n",r);
}
int main() {
	int T;
//	T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}
/*
1
4 1
5 10 11 5

*/