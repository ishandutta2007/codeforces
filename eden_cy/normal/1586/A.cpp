#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;

const int N=1e5+50;
int a[N];
bool f(int x) {
	for(int i=2; i*i<=x; ++i) {
		if(x%i==0) return 1;
	}
	return 0;
}
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	int t=0;
	FOR(i,1,n) t+=a[i];
	if(f(t)) {
		printf("%d\n",n);
		FOR(i,1,n) printf("%d ",i);
		putchar('\n');
		return ;
	}
	FOR(i,1,n) if(f(t-a[i])) {
		printf("%d\n",n-1);
		FOR(j,1,n) if(j!=i) printf("%d ",j);
		putchar('\n');
		return ;
	}
	FOR(i,1,n) FOR(j,i+1,n) if(f(t-a[i]-a[j])) {
		printf("%d\n",n-2);
		FOR(k,1,n) if(k!=i && k!=j) printf("%d ",k);
		putchar('\n');
		return ;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}