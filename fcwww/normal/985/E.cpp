#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500050
int n,a[N],K,d,f[N],Q[N],l,r;
int main() {
	scanf("%d%d%d",&n,&K,&d);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	Q[r++]=0;
	for(i=K;i<=n;i++) {
		while(l<r&&a[i]-a[Q[l]+1]>d) l++;
		if(l<r) f[i]=1;
		int t=i-K+1;
		if(f[t]) {
			while(l<r) r--;
			Q[r++]=t;
		}
	}
	puts(f[n]?"YES":"NO");
}