#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 110;
int a[N], b[N], n, m;
int main() {
	n = read(), m = read();
	if (m > 1) {
		puts("Yes");
		return 0;
	}
	a[0] = -INF;
	int last = 0, zhi;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i]) {
			if (a[i] < a[last]){
				puts("Yes");
				return 0;
			}
			last = i;
		} else zhi = i;
	}
	b[1] = read();
//	cout << zhi << endl;
	if (b[1] < a[zhi-1] || (b[1] > a[zhi+1] && zhi+1<=n)) puts("Yes");
	else puts("No");
}