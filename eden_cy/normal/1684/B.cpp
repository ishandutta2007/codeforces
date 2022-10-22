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
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d %d %d\n",a+b+c,b+c,c);
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