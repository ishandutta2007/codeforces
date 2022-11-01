// Skyqwq
#include <iostream>
#include <cstdio>

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

const int N = 1e5 + 5, P = 998244353;

int fact[N << 1], infact[N << 1];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}
void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}

int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int n;

char s[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int inline get(int n, int k) {
    return C(n + k - 1, k - 1);
}
 
int main() {
    factPrework(200000);
    int T; read(T);
    while (T--) {
        read(n); scanf("%s", s + 1);
        int a = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') continue;
            int j = i;
            while (j < n && s[j + 1] == '1') j++;
            a += (j - i + 1) / 2;
            if ((j - i + 1) & 1) c++;
            i = j;
        }
        int b = (n - (a * 2)) + 1 - c;
        int ans = get(a, b);
        printf("%d\n", ans);
    }
    return 0;
}