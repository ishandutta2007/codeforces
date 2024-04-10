#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 2010, M = 210, PC = 3;

int p[PC] = {1000000007, 1000000009, 1000000011};

int n, m;
int m26[PC], m2626[PC];
char s[N];
int hsh1[N][PC], hsh2[M][N][PC];

int main() {
	scanf("%d%d", &n, &m);
	for (int k = 0; k < PC; ++k) {
		m26[k] = 1;
		for (int i = 1; i <= m; ++i)
			m26[k] = m26[k] * 26LL % p[k];
		m2626[k] = 1;
		for (int i = 1; i <= m; ++i)
			m2626[k] = m2626[k] * (ll)m26[k] % p[k];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		static int h1[PC];
		memset(h1, 0, sizeof(h1));
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k < PC; ++k)
				h1[k] = (h1[k] * 26LL + (s[j] - 'a')) % p[k];
		for (int k = 0; k < PC; ++k)
			hsh1[i][k] = (hsh1[i - 1][k] * (ll)m26[k] + h1[k]) % p[k];
	}
	for (int i = n; i >= m; --i)
		for (int k = 0; k < PC; ++k)
			hsh1[i][k] = ((hsh1[i][k] - hsh1[i - m][k] * (ll)m2626[k]) % p[k] + p[k]) % p[k];
	for (int i = 1; i <= m; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k < PC; ++k)
				hsh2[i][j][k] = (hsh2[i][j - 1][k] * 26LL + s[j] - 'a') % p[k];
	}
	for (int i = 1; i <= m; ++i)
		for (int j = n; j >= m; --j)
			for (int k = 0; k < 3; ++k)
				hsh2[i][j][k] = ((hsh2[i][j][k] - hsh2[i][j - m][k] * (ll)m26[k]) % p[k] + p[k]) % p[k];
	for (int i = 1; i <= m; ++i)
		for (int j = m; j <= n; ++j)
			for (int k = 0; k < 3; ++k) {
				hsh2[i][j][k] = (hsh2[i][j][k] + hsh2[i - 1][j][k] * (ll)m26[k]) % p[k];
			}
	for (int i = m; i <= n; ++i)
		for (int j = m; j <= n; ++j) {
			bool flag = true;
			for (int k = 0; k < PC; ++k)
				flag &= hsh1[i][k] == hsh2[m][j][k];
			if (flag) {
				printf("%d %d\n", i - m + 1, j - m + 1);
				return 0;
			}
		}
	return 0;
}