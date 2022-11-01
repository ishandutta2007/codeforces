#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace IO {
    const int MAXR = 10000000;
    char _READ_[MAXR], _PRINT_[MAXR];
    int _READ_POS_, _PRINT_POS_, _READ_LEN_;
    inline char readc() {
    #ifndef ONLINE_JUDGE
        return getchar();
    #endif
        if (!_READ_POS_) {
            if (feof(stdin)) return -1;
            _READ_LEN_ = fread(_READ_, 1, MAXR, stdin);
        }
        char c = _READ_[_READ_POS_++];
        if (_READ_POS_ == _READ_LEN_) _READ_POS_ = 0;
        return c;
    }
    template<typename T> inline int read(T &x) {
        x = 0; register int flag = 1, c;
        while (((c = readc()) < '0' || c > '9') && c != '-')
            if (c < 0) return -1;
        if (c == '-') flag = -1; else x = c - '0';
        while ((c = readc()) >= '0' && c <= '9') x = x * 10 - '0' + c;
        x *= flag; return 0;
    }
    inline int read(char *s) {
        register int len = 0, c;
        while (isspace(c = readc()) || c <= 0)
            if (c < 0) return -1;
        s[len++] = c;
        while (!isspace(c = readc()) && c) s[len++] = c;
        s[len] = 0;
        return len;
    }
    template<typename T1, typename ...T2> inline int read(T1 &a, T2&... x) {
        return read(a) | read(x...);
    }
    inline void ioflush() { fwrite(_PRINT_, 1, _PRINT_POS_, stdout), _PRINT_POS_ = 0; fflush(stdout); }
    inline void printc(char c) {
        if (!c) return;
        _PRINT_[_PRINT_POS_++] = c;
        if (_PRINT_POS_ == MAXR) ioflush();
    }
    template<typename T> inline void print(T x, char c = '\n') {
        if (x < 0) printc('-'), x = -x;
        if (x) {
            static char sta[20];
            register int tp = 0;
            for (; x; x /= 10) sta[tp++] = x % 10 + '0';
            while (tp > 0) printc(sta[--tp]);
        } else printc('0');
        printc(c);
    }
    inline void print(char *s, char c = '\n') {
        for (int i = 0; s[i]; i++) printc(s[i]);
        printc(c);
    }
    inline void print(const char *s, char c = '\n') {
        for (int i = 0; s[i]; i++) printc(s[i]);
        printc(c);
    }
    template<typename T1, typename ...T2> inline void print(T1 x, T2... y) {
        print(x, ' '), print(y...);
    }
}
using namespace IO;

const int MAXN = 1505;
const LL MOD = 1000000000000037ll;
int A[MAXN][MAXN], B[MAXN][MAXN], vis[MAXN], id[MAXN], n, m;
LL hsh[MAXN];
int arr[MAXN], cnt[MAXN], cut[MAXN];

int main() {
//	freopen("input.txt", "r", stdin);
	IO::read(n, m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		IO::read(A[i][j]);
		hsh[i] = (hsh[i] * 233 + A[i][j]) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		LL h = 0;
		for (int j = 1; j <= m; j++) {
			IO::read(B[i][j]);
			h = (h * 233 + B[i][j]) % MOD;
		}
		for (int j = 1; j <= n; j++) if (!vis[j] && hsh[j] == h) {
			id[i] = j, vis[j] = 1;
			break;
		}
		if (!id[i]) return puts("-1"), 0;
	}
	bool same = 1;
	for (int i = 1; i <= n; i++) {
		if (id[i] != i) { same = 0; break; }
	}
	if (same) return puts("0"), 0;
	memset(vis, 0, sizeof(vis));
	int all = 0;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j < n; j++)
		cnt[i] += B[j][i] > B[j + 1][i];
	while (true) {
		bool hav = 0;
		for (int i = 1; i <= m; i++) if (!vis[i] && !cnt[i]) {
			for (int j = 1; j < n; j++) if (!cut[j] && B[j][i] < B[j + 1][i]) {
				cut[j] = 1;
				for (int k = 1; k <= m; k++) if (!vis[k] && B[j][k] > B[j + 1][k]) --cnt[k];
			}
			arr[++all] = i;
			vis[i] = hav = 1;
		}
		if (!hav) break;
	}
	int yes = 1;
	for (int i = 1; i < n; i++) {
		if (id[i] > id[i + 1] && !cut[i]) {
			yes = 0; break;
		}
	}
	if (yes) {
		printf("%d\n", all);
		for (int i = all; i > 0; i--) printf("%d ", arr[i]);
	} else puts("-1");
	return 0;
}