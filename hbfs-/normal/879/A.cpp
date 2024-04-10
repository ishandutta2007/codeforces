#include <bits/stdc++.h>
#define N 1000500
typedef long long LL;
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int n;

int main() {
	n = rd();
	int cur = 0;
	for (int i=1;i<=n;i++) {
		int s = rd(), d = rd();
		int t = (cur-s) / d;
		if (cur < s) {
			cur = s;
			continue;
		}
		if (t*d+s > cur)
			cur = t*d+s;
		else
			cur = (t+1)*d+s;
	}
	cout << cur << endl;
	return 0;
}