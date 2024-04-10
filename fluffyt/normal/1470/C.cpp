#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN], n, K;
vector<int> rem;
int ask(int p) {
	printf("? %d\n", p);
	fflush(stdout);
	int r; scanf("%d", &r);
	return r;
}

int dis(int a, int b) {
	return min(abs(a - b), n - abs(a - b));
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) a[i] = K;
	for (int i = 1; i <= n; i++) rem.push_back(i);
	ask(1);
	for (int i = 1;;) {
		int p = rem[min(i, (int)rem.size()) - 1];
		int r = ask(p);
		bool flag = false;
		++i;
		if (r != K) flag = true;
		else ++i, p = p % n + 1, r = ask(p);
		if (r != K) flag = true;
		if (!flag) {
			vector<int> tmp;
			for (int j : rem)
				if (dis(j, p) >= i - 1) tmp.push_back(j);
			rem = tmp;
		} else {
			if (r < K) {
				int lst = r, u = p;
				for (int j = p;; j = j % n + 1) {
					int t = ask(j);
					if (t > lst) return printf("! %d\n", u % n + 1), 0;
					else lst = t, u = j;
				}
			} else {
				int lst = r;
				for (int j = p;; j = (j - 2 + n) % n + 1) {
					int t = ask(j);
					if (t < lst) return printf("! %d\n", j), 0;
					else lst = t;
				}
			}
		}
	}
	return 0;
}