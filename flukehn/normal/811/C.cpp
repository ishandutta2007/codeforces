#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void){
	int x = 0, c = 0, f = 1;
	for (;c<'0'||c>'9';c=getchar())f=c!='-';
	for (;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
int f[5100], n, a[5100], L[5100], R[5100];
bool vis[5100], ok[5100];
int main() {
	n = read();
	memset(L, 0x3f, sizeof L);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
		R[a[i]] = max(R[a[i]], i), L[a[i]] = min(L[a[i]], i);
	for (int i = 1; i <= n; i++) {
		int now = 0, t = INF;
		f[i] = f[i - 1];
		if (R[a[i]] != i) continue;
		memset(ok , 0, sizeof ok);
		for (int j = i; j; j--) {
			now ^= ok[a[j]] ? 0 : a[j];
			t = min(t, L[a[j]]);
			ok[a[j]] = 1;
			if (R[a[j]] > i) break;
			if (t >= j) 
				f[i] = max(f[i], f[j - 1] + now);
		}
	}
	printf("%d\n",f[n]);
}