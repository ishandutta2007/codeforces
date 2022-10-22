#include <bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		scanf("%s", s);
		int k; scanf("%d", &k);
		static set <char> spc; spc.clear();
		while (k--) {
			static char buf[10]; scanf("%s", buf);
			spc.insert(buf[0]);
		}
		static vector <int> a; a.clear();
		for (int i = 0; i < n; i++) {
			if (spc.count(s[i])) a.push_back(i);
		}
		int turn = 0;
		while (a.size() > 1 || a.size() && a[0]) {
			turn++;
			int flag = a[0] > 0;
			for (int i = 0; i < a.size(); i++) {
				a[i] = a[i] - i - flag;
			}
			a.resize(unique(a.begin(), a.end()) - a.begin());
		}
		printf("%d\n", turn);
	}
	return 0;
}