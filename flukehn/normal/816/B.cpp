#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 200010;
int f[N];
int main() {
	int n = read(), k = read(), q = read();
	for (int i = 1; i <= n; i++) {
		int l = read(), r = read();
		f[l]++,f[r+1]--;
	}
	for (int i = 1; i <= N; i++)
		f[i] += f[i-1];
	for (int i = 1; i <= N; i++)
		f[i] = (f[i] >= k) + f[i-1];
	for (int i = 1; i <= q; i++) {
		int l = read(), r = read();
		printf("%d\n",f[r]-f[l-1]);
	}
}