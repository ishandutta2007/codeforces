#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 100010;

int cnt;
char s[N], t[N];
char ans[N][2];

int f[26];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	int n;
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < 26; ++i)
		f[i] = i;
	for (int i = 0; i < n; ++i) {
		if (find(s[i] - 'a') == find(t[i] - 'a'))
			continue;
		ans[++cnt][0] = s[i];
		ans[cnt][1] = t[i];
		f[find(s[i] - 'a')] = f[find(t[i] - 'a')];
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; ++i)
		printf("%c %c\n", ans[i][0], ans[i][1]);
	return 0;
}