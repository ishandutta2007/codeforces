#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10, P = 1e9 + 7;

int n, m;
char s[N];
int pw[N], a[26], b[26];
int hsh[26][N];

int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = pw[i - 1] * 2;
		if (pw[i] >= P)
			pw[i] -= P;
	}
	for (int i = 1; i <= n; ++i)
		s[i] -= 'a';
	for (int c = 0; c < 26; ++c) {
		for (int i = 1; i <= n; ++i) {
			hsh[c][i] = hsh[c][i - 1] * 2 + (s[i] == c);
			if (hsh[c][i] >= P)
				hsh[c][i] -= P;
		}
	}
	while (m--) {
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		for (int c = 0; c < 26; ++c) {
			a[c] = (hsh[c][x + len - 1] - (ll) pw[len] * hsh[c][x - 1]) % P;
			if (a[c] < 0)
				a[c] += P;
		}
		for (int c = 0; c < 26; ++c) {
			b[c] = (hsh[c][y + len - 1] - (ll) pw[len] * hsh[c][y - 1]) % P;
			if (b[c] < 0)
				b[c] += P;
		}
		sort(a, a + 26);
		sort(b, b + 26);
		bool flag = true;
		for (int c = 0; c < 26; ++c)
			if (a[c] != b[c]) {
				flag = false;
				break;
			}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}