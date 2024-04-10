#include <bits/stdc++.h>
#define N 1000050

using namespace std;
inline int rd() { int r; scanf("%d",&r); return r; }
int n,k,ans,l,h,p,a[N],b[N];
char s[N];
int main() {
	n = rd() , k = rd();
	for (int i=1;i<=n;i++) a[i] = rd() , ans += a[i];
	for (int i=1;i<=n;i++) b[i] = rd() - a[i];
	sort(b+1,b+n+1);
	k = n-k;
	for (int i=1;i<=k;i++) ans = min(ans , ans+b[i]);
	printf("%d\n",ans);
	return 0;
}