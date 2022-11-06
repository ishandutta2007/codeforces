#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define clr(a) memset(a,0,sizeof(a))
int n,p[1010000];
int main() {
	scanf("%d",&n);
	if (n%4==2||n%4==3) {
		puts("-1");
		return 0;
	}
	if (n%4==0) {
		for (int i=1;i<=n/2;i++) {
			if (i%2==1) p[i]=i+1,p[n+1-i]=n-i;
			else p[i]=n+2-i,p[n+1-i]=i-1;
		}
		for (int i=1;i<=n;i++) printf("%d ",p[i]);		
	} else {
		for (int i=1;i<=n/2;i++) {
			if (i%2==1) p[i]=i+1,p[n+1-i]=n-i;
			else p[i]=n+2-i,p[n+1-i]=i-1;
		}
		p[n/2+1]=n/2+1;
		for (int i=1;i<=n;i++) printf("%d ",p[i]);
	}
}