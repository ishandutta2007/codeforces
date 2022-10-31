#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
typedef long long ll;
ll n;
int main() {
	scanf("%lld",&n);
	ll s=n*(n+1)/2;
	int i,j;
	for(i=2;i<=n;i++) {
		if((s-i)%i==0) {
			puts("Yes");
			printf("1 %d\n",i);
			printf("%lld",n-1);
			for(j=1;j<=n;j++) if(j!=i) printf(" %d",j);
			puts(""); return 0;
		}
	}
	puts("No");
}