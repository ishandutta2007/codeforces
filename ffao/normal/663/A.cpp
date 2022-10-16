#include <bits/stdc++.h>
using namespace std;


char s[11000];
int sign[110];
int val[110];

void solve() {
	gets(s);

	int l = strlen(s);
	int sg = 1;
	int n;
	int qs = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] == '?') sign[qs++] = sg;
		if (s[i] == '+') sg = 1;
		if (s[i] == '-') sg = -1;
		if (s[i] == '=') {
			stringstream ss;
			ss << (s+(i+1));
			ss >> n;
		}
	}	

	int cur = 0;
	for (int i = 0; i < qs; i++) {
		val[i] = 1;
		cur += sign[i];
	}

	for (int i = 0; i < qs; i++) {
		if (cur < n && sign[i] == 1) {
			int ta = min(n-1, n-cur);
			val[i] += ta;
			cur += ta;
		}
		if (cur > n && sign[i] == -1) {
			int ta = min(n-1, cur-n);
			val[i] += ta;
			cur -= ta;
		}
	}

	if (cur != n) {
		printf("Impossible\n"); return;
	}

	printf("Possible\n");
	for (int i = 0; i < qs; i++) {
		if (i != 0) {
			printf("%c ", (sign[i] == 1 ? '+' : '-'));
		}
		printf("%d ", val[i]);
	}
	printf("= %d\n", n);

}

int main() {
    solve();
}