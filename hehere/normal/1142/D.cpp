#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 100000 + 233;
int n;
char s[maxN];

int ch[11 * 11 * 11][10];
int encode(int x, int y, int z) {
	return (x * 11 + y) * 11 + z; 
}
void decode(int code, int &x, int &y, int &z) {
	z = code % 11; code /= 11;
	y = code % 11; code /= 11;
	x = code % 11; code /= 11;
}

void generate() {
	for(int code = 0; code < 11 * 11 * 11; ++code) {
		for(int d = 0; d < 10; ++d) {
			int x, y, z; decode(code, x, y, z);
			int &nxt = ch[code][d];
			int nx = z + 1, ny = nx - 1, nz = nx - 1;
			for(int i = x; i < y + 11; ++i) ny += i % 11; ny += d + 1;
			for(int i = x; i <= z + 11; ++i) nz += i % 11;
			nx %= 11; ny %= 11; nz %= 11;
			if(d < y) nxt = encode(nx, ny, nz);
			else nxt = -1;
		}
	}
}

LL f[2][11 * 11 * 11];

int main() {
	ios::sync_with_stdio(false);
	cin >> (s + 1);
	n = strlen(s + 1);
	generate();
	memset(f, 0, sizeof(f));
	int p = 0;
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		int c = s[i] - '0';
		p ^= 1;
		memset(f[p], 0, sizeof(f[p]));
		if(c) f[p][encode(1, c, 9)] = 1;
		for(int j = 0; j < 11 * 11 * 11; ++j)
			if(ch[j][c] != -1)
				f[p][ch[j][c]] += f[p ^ 1][j];
		for(int j = 0; j < 11 * 11 * 11; ++j)
			ans += f[p][j];
	}
	cout << ans << endl;
	return 0;
}