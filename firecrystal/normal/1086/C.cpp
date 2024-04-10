// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 1e6 + 5, S = 26;

int n, p[S], vis[S], bp[S], bv[S];

char s[N], a[N], b[N];


int k;

void fill() {
    for (int i = 0; i < k; i++) {
        if (p[i] == -1) {
            for (int j = 0; j < k; j++) {
                if (!vis[j]) {
                    vis[j] = 1, p[i] = j;
                    break;
                }
            }
        }
    }
}

void inline out() {
    puts("YES");
    for (int i = 0; i < k; i++)
        putchar('a' + p[i]);
    puts("");
}

void inline copy() {
    memcpy(bp, p, sizeof bp);
    memcpy(bv, vis, sizeof bv);
}
 
void inline back() {
    memcpy(p, bp, sizeof bp);
    memcpy(vis, bv, sizeof bv);
}

bool inline workA(int pos) {
    for (int i = pos + 1; i <= n; i++) {
        int ch = s[i] - 'a', t = a[i] - 'a';    
        if (~p[ch]) {
            if (p[ch] < t) return 0;
            if (p[ch] > t) break;
        } else {
            for (int j = t + 1; j < k; j++) {
                if (!vis[j]) {
                    p[ch] = j;
                    vis[j] = 1;
                    fill();
                    out();
                    return 1;
                }
            }
            if (!vis[t]) {
                p[ch] = t;
                vis[t] = 1;
            } else {
                return 0;
            }
        }
    }

    fill();
    out();
    return 1;
}

bool inline workB(int pos) {
    for (int i = pos + 1; i <= n; i++) {
        int ch = s[i] - 'a', t = b[i] - 'a';    
        if (~p[ch]) {
            if (p[ch] > t) return 0;
            if (p[ch] < t) break;
        } else {
            for (int j = 0; j < t; j++) {
                if (!vis[j]) {
                    p[ch] = j;
                    vis[j] = 1;
                    fill();
                    out();
                    return 1;
                }
            }
            if (!vis[t]) {
                p[ch] = t;
                vis[t] = 1;
            } else {
                return 0;
            }
        }
    }

    fill();
    out();
    return 1;
}

int main() {
    int T; read(T);
    while (T--) {
        memset(p, -1, sizeof p);
        memset(vis, 0, sizeof vis);
        read(k);
        scanf("%s%s%s", s + 1, a + 1, b + 1);
        n = strlen(s + 1);
        int i = 0; bool o = 1;
        while (i < n && a[i + 1] == b[i + 1]) {
            ++i;
            if (~p[s[i] - 'a'] && p[s[i] - 'a'] != a[i] - 'a') {
                o = 0;
                break;
            }
            if (p[s[i] - 'a'] == -1 && vis[a[i] - 'a']) {
                o = 0;
                break;
            }
            p[s[i] - 'a'] = a[i] - 'a';
            vis[a[i] - 'a'] = 1;
        }
        if (!o) puts("NO");
        else if (i == n) {
            fill();
            out();
        } else {
            o = 0;
            ++i;
            int ch = s[i] - 'a', L = a[i] - 'a', R = b[i] - 'a';
            if (~p[ch]) {
                if (p[ch] < L || p[ch] > R) puts("NO");
                else if (p[ch] > L && p[ch] < R) {
                    fill();
                    out();
                } else if (p[ch] == L) {
                    if (!workA(i)) puts("NO");
                } else {
                    if (!workB(i)) puts("NO");
                }
            } else {
                bool o = 0;
                for (int i = L + 1; i < R; i++) {
                    if (!vis[i]) {
                        vis[i] = 1, p[ch] = i;
                        o = 1;
                        fill();
                        out();
                        break;
                    }
                }
                if (!o) {
                    if (!vis[L]) {
                        copy();
                        vis[L] = 1, p[ch] = L;
                        o |= workA(i);
                        back();
                    }

                    if (!o && !vis[R]) {
                        copy();
                        vis[R] = 1, p[ch] = R;
                        o |= workB(i);
                        back();
                    }
                    if (!o) puts("NO");
                }
            }
        }
    }
	return 0;
}