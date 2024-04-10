#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int n;
int a[311];

int main() {
	n=rd();
	int ans = 0, cnt = 0, speed = 0;
	for (int i = 1; i <= n; ++i) {
		int t, x;
		t=rd();
		if (t == 1) {
			x=rd();
			speed = x;
			for (int i = x-1; i; --i)
				ans += a[i], a[i] = 0;
		} else if (t == 2) {
			ans += cnt;
			cnt = 0;
		} else if (t == 3) {
			x=rd();
			if (x < speed) ++ans;
			else {
				++a[x];
				for (int i = x-1; i; --i)
					a[x] += a[i], a[i] = 0;
			}
		} else if (t == 4) {
			cnt = 0;
		} else if (t == 5) {
			memset(a, 0, sizeof a);
		} else {
			++cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}