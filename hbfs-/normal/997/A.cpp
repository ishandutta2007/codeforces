#include <bits/stdc++.h>
#define N 3000500
using namespace std;
typedef long long LL;
LL ans;
int n,x,y;
char s[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), x = rd(), y = rd();
	x = min(x, y);
	scanf("%s",s+1);
	int l = 1, flag = 0;
	for (int i=1;i<=n;i++) {
		if (s[i] == '0') {
			if (l == 1) ans += x;
			l = 0;
			flag = 1;
		} else {
			l = 1;
		}
	}
	if (!flag) puts("0"); else {
		ans = ans - x + y;
		cout << ans << endl;
	}
	return 0;
}