#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef double f2;
ll p,q,b;
int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
bool solve() {
	if(p==0||q==1) return 1;
	ll d=__gcd(p,q);
	p/=d; q/=d;
	int i;
	for(i=0;i<17;i++) {
		if(b%a[i]==0&&q%a[i]==0) {
			while(q%a[i]==0) q/=a[i];
		}
	}
	while(1) {
		if(q==1) return 1;
		d=__gcd(b,q);
		if(d==1) return 0;
		while(q%d==0) q/=d;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld%lld",&p,&q,&b);
		int tmp=solve();
		puts(tmp?"Finite":"Infinite");
	}
}