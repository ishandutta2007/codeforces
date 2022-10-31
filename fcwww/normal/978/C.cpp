#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define N 200050
int n,m;
ll a[N],s[N],q[N];
int main() {
	scanf("%d%d",&n,&m);
	int i,nowf=1;
	ll x,now=0;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=m;i++) {
		scanf("%lld",&x);
		while(now+a[nowf]<x) {
			now+=a[nowf]; nowf++;
		}
		printf("%d %lld\n",nowf,x-now);
	}
}