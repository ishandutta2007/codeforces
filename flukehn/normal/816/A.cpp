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
int calc(int x) {return x / 10 + (x % 10) * 10;}
int judge(int x,int y) { return calc(x)==y;}
int main() {
	int n = read(), m = read(), ans = 0;
	while (!judge(n, m)) {
		int y = calc(n);
		if (y < 60 && y > m) {
			ans += y - m; break;
		}
		else n=(n+1)%24, ans += 60 - m, m = 0;
	} 
	cout << ans << endl;
}