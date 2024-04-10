#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
#define N 100050
struct A {
	ll sum;
	int id;
	bool operator < (const A &x) const {
		return sum==x.sum?id<x.id:sum>x.sum;
	}
}a[N];
int n;
int main() {
	scanf("%d",&n);
	int i;
	ll x,y,z,w;
	for(i=1;i<=n;i++) {
		scanf("%lld%lld%lld%lld",&x,&y,&z,&w); a[i].sum=x+y+z+w; a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) if(a[i].id==1) {
		printf("%d\n",i); return 0;
	}
}