#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	vector<int> cnt(256);
	int n = nxt();
	string s;
	cin >> s;

	for (char c : s) {
		cnt[c] += 1;
	}

	int cnt_odd = 0;
	for (int i = 0; i < 256; ++i) {
		if (cnt[i] % 2) {
			++cnt_odd;
		}
	}

	for (int num = 1; num <= n; ++num) {
		if (n % num) {
			continue;
		}
		if (n / num % 2 && num >= cnt_odd) {
			printf("%d\n", num);
			vector<int> odd;
			for (int i = 0; i < 256; ++i) {
				if (cnt[i] % 2) {
					odd.push_back(i);
					cnt[i] -= 1;
				}
			}
			for (int i = 0; i < 256; ++i) {
				while (cnt[i] && (int)odd.size() < num) {
					cnt[i] -= 1;
					odd.push_back(i);
				}
			}
			vector<string> str(num);
			int len = n / num / 2;
			int idx = 0;
			for (int i = 0; i < 256; ++i) {
				while (cnt[i]) {
					while ((int)str[idx].length() == len) {
						++idx;
					}
					str[idx] += (char)i;
					cnt[i] -= 2;
				}
			}
			for (int i = 0; i < num; ++i) {
				printf("%s", str[i].c_str());
				printf("%c", odd[i]);
				reverse(all(str[i]));
				printf("%s ", str[i].c_str());
			}
			printf("\n");
			return 0;
		}
		if (n / num % 2 == 0 && cnt_odd == 0) {
			printf("%d\n", num);
			vector<string> str(num);
			int len = n / num / 2;
			int idx = 0;
			for (int i = 0; i < 256; ++i) {
				while (cnt[i]) {
					while ((int)str[idx].length() == len) {
						++idx;
					}
					str[idx] += (char)i;
					cnt[i] -= 2;
				}
			}
			for (int i = 0; i < num; ++i) {
				printf("%s", str[i].c_str());
				reverse(all(str[i]));
				printf("%s ", str[i].c_str());
			}
			printf("\n");
			return 0;
		}
	}

	return 0;
}