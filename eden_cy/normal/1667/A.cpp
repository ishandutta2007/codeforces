#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;
const int N=5005;
int a[N];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	ll r=1e18;
	FOR(i,0,n) {
		ll t=0;
		ll p=0;
		DOR(j,i,1) {
			ll s=(p+a[j]-1)/a[j];
			p=s*a[j]+1;
			t+=s;
		}
		p=1;
		FOR(j,i+1,n) {
			ll s=(p+a[j]-1)/a[j];
			p=s*a[j]+1;
			t+=s;
		}
		r=min(r,t);
	}
	printf("%lld\n",r);
	return 0;
}