#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

LL gcd(LL a, LL b) {
	return b==0 ? a : gcd(b,a%b);
}
LL lcm(LL a, LL b) {
	return a*b / gcd(a,b);
}

int main() {
	LL n; cin>>n;
	LL ans=-1;
	for(LL a=n; a>=max(1LL,n-10); --a)
	for(LL b=n; b>=max(1LL,n-10); --b)
	for(LL c=n; c>=max(1LL,n-10); --c) {
		LL tmp=lcm(lcm(a,b), c);
		ans=max(ans, tmp);
	}
	cout<<ans<<endl;
	return 0;
}