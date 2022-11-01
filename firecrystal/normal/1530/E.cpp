// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, c[26], cnt[26], A, B, p, ans[N];
 
char s[N];

bool inline ok() {
    if (A != B) {
        int la = n - p - cnt[A] - cnt[B];
        if (cnt[B]) {
            if (ans[p] == A) {
                return la > 0;
            }
        }
        return 1;
    } else {
        int la = n - p - cnt[A];
        if (ans[p] == A) {
            return la >= cnt[A];
        } else return la >= cnt[A] - 1;
    }
}

bool inline check(int a, int b) {
    A = a, B = b;
    ans[1] = a, ans[2] = b;
    memcpy(cnt, c, sizeof cnt);
    cnt[a]--, cnt[b]--;
    if (cnt[a] < 0 || cnt[b] < 0) return 0;
    p = 2;
    if (!ok()) return 0;
    for (int i = 3; i <= n; i++) {
        p = i;
        bool f = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j]) {
                if (j == B && ans[i - 1] == A) continue;
                ans[i] = j;
                cnt[j]--;
                if (ok()) {
                    
                    f = 1;
                    break;
                }
                cnt[j]++;
            }
        }
        if (!f) return 0;
    }
    for (int i = 1; i <= n; i++) putchar(ans[i] + 'a');
    puts("");
    return 1;
}

int main() {
    int T; read(T);
    while (T--) {
        memset(c, 0, sizeof c);
        scanf("%s", s + 1);
        n = strlen(s + 1);
        bool o = 0, o2 = 1;
        for (int i = 1; i <= n; i++) c[s[i] - 'a']++;
        int z = -1;
        for (int i = 0; i < 26; i++) {
            if (c[i] == n) o = 1;
            if (c[i] > 1) o2 = 0;
            if (z == -1 && c[i] == 1) {
                z = i;
            }
        }
        if (o2 || o) {
            sort(s + 1, s + 1 + n);
            for (int i = 1; i <= n; i++) putchar(s[i]);
            puts("");
            continue;
        }
        if (z != -1) {
            c[z]--;
            putchar('a' + z);
            for (int i = 0; i < 26; i++) {
                while (c[i]--) putchar(i + 'a');
            }
            puts("");
            continue;
        }
        bool ok = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (check(i, j)) {
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }
    }
    return 0;
}