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

void solve() {
	int n;
	scanf("%d",&n);
	if(n<=99) printf("%d\n",n%10);
	else {
		int x=10;
		while(n) x=min(x,n%10),n/=10;
		printf("%d\n",x);
	}
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