#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1e5+50;
int a[N];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) {
		int c=0;
		FOR(j,2,i+1) {
			if(a[i]%j) {c=1;break;}
		}
		if(c==0) {puts("NO");return ;}
	}
	puts("YES");
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}