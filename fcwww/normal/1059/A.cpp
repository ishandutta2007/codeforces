#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
#define N 100050
int n,t[N],l[N],A,ans;
int main() {
	int L;
	scanf("%d%d%d",&n,&L,&A);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&t[i],&l[i]);
	}
	t[n+1]=L;
	for(i=1;i<=n+1;i++) {
		ans+=(t[i]-(t[i-1]+l[i-1]))/A;
	}
	printf("%d\n",ans);
}