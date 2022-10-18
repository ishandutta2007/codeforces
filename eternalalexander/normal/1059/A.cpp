#include <cstdio>

int n, l, a;
int s[100005], t[100005];

int main() {
	scanf("%d %d %d", &n, &l, &a);
	for (int i=1;i<=n;++i) scanf("%d %d", &s[i], &t[i]);
	s[0]=0; t[0]=0; s[n+1]=l; t[n+1]=l;
	int ans=0;
	for (int i=1;i<=n+1;++i) {
		ans+=(s[i]-(s[i-1]+t[i-1]))/a;
	}printf("%d", ans);
	return 0;
}