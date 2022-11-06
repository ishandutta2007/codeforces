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
int a[11000], n, m;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1, l, r, x, t; i <= m; i++) {
		l =  read(), r = read(), x = read(), t = a[x];
		int tot = 0;
		for (int j = l; j <= r; j++)
			tot += a[j] < t;
		puts(tot == x - l? "Yes" : "No");
	}
}