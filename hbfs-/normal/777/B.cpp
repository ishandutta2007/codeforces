#include <bits/stdc++.h>
#define N 1000050
using namespace std;
int n,m,a[N],b[N],ans1,ans2;
char s[N];

inline void solve1() {
	int t = 1;
	for (int i=1;i<=n;i++) 
		if (b[i] >= a[t]) ans1-- , t++;
}
inline void solve2() {
	int t = 1;
	for (int i=1;i<=n;i++) {
		if (b[i] > a[t]) ans2++ , t++;
	}
}

int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i] = s[i] - '0';
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) b[i] = s[i] - '0';
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	ans1 = n;
	solve1();
	solve2();
	printf("%d\n%d\n",ans1,ans2);
	
	return 0;
}