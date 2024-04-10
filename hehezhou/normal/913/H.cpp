#include <bits/stdc++.h>
using namespace std;
const int D = 8, mod = 998244353, G = 3;
typedef unsigned long long ull;
typedef unsigned long long ll;

const int BUFLENGTH = 1 << 21;
struct FASTIO {
    char rBUF[BUFLENGTH], wBUF[BUFLENGTH], *rST, *rEN, *wEN;
    inline int gc() { return rST == rEN && (rST = rBUF, rEN = rBUF + fread(rBUF, 1, BUFLENGTH, stdin), rST == rEN) ? EOF : *rST++; }
    inline void flush() { fwrite(wBUF, 1, wEN - wBUF, stdout); wEN = wBUF; }
    inline void putchar(int x) { if (wEN == wBUF + BUFLENGTH) flush(); *wEN++ = x; }
    FASTIO() { rST = rEN = rBUF; wEN = wBUF; }
    ~FASTIO() { flush(); }
    
    template < class T >
    inline void read(T &x) {
        int c = gc(), f = 0;
        x = 0;
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = x * 10 + c - '0', c = gc();
        if (f) x = -x;
    }
    template < class T, class ...res >
    inline void read(T &x, res &...A) { read(x), read(A...); }
    inline string readString() {
        string ans = "";
        int c = gc();
        while (isspace(c)) c = gc();
        while (!isspace(c)) ans += c, c = gc();
        return ans;
    }
    inline string readLine() {
        string ans = "";
        int c = gc();
        while (c != '\n' && c != EOF) ans += c, c = gc();
        return ans;
    }
    
    template < class T >
    void writePos(T x) {
        if (x >= 10) writePos(x / 10);
        putchar(x % 10 + '0');
    }

    template < class T, typename = typename std::enable_if<std::is_integral<T>::value>::type >
    inline void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        writePos(x);
    }
    inline void write(char x) { putchar(x); }
    inline void write(const string &s) { for (auto x : s) putchar(x); }
    inline void write(char *s) { for (; *s; s++) putchar(*s); }
    template < class T, class ...res >
    inline void write(T x, const res &...A) { write(x), write(A...); }
    
    template < class T >
    inline FASTIO& operator << (const T &x) {
        write(x);
        return *this;
    }
    template < class T >
    inline FASTIO& operator >> (T &x) {
        read(x);
        return *this;
    }
} IO;

inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
inline int Mod(int x) {return x >= mod ? x - mod : x;}
struct mint {
    int x;
    mint() {x = 0;}
    mint(int y) {x = y;}
    inline mint inv() const { return mint{power(x, mod - 2)}; }
    explicit inline operator int() { return x; }
    friend inline mint operator + (const mint &a, const mint& b) { return mint(Mod(a.x + b.x)); }
    friend inline mint operator - (const mint &a, const mint& b) { return mint(Mod(a.x - b.x + mod)); }
    friend inline mint operator * (const mint &a, const mint& b) { return mint(1ll * a.x * b.x % mod); }
    friend inline mint operator - (const mint &a) { return mint(Mod(mod - a.x)); }
    friend inline mint& operator += (mint &a, const mint& b) { return a = a + b; }
    friend inline mint& operator -= (mint &a, const mint& b) { return a = a - b; }
    friend inline mint& operator *= (mint &a, const mint& b) { return a = a * b; }
    inline int operator == (const mint &b) { return x == b.x; }
    inline int operator != (const mint &b) { return x != b.x; }
    inline int operator < (const mint &a) { return x < a.x; }
    inline int operator <= (const mint &a) { return x <= a.x; }
    inline int operator > (const mint &a) { return x > a.x; }
    inline int operator >= (const mint &a) { return x >= a.x; }
};
typedef vector < mint > poly;
inline mint power(mint a, int b) {
    mint ans = 1;
    for (; b; b >>= 1, a = a * a) if (b & 1) ans = ans * a;
    return ans;
}
mint fac[1 << D | 10], facinv[1 << D | 10], inv[1 << D | 10];
inline void init() {
    inv[1] = 1;
    for (int i = 2; i <= 1 << D; i++) inv[i] = (mod - mod / i) * inv[mod % i];
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= 1 << D; i++) fac[i] = fac[i - 1] * i, facinv[i] = facinv[i - 1] * inv[i];
}
int n;
int a[75];
int split[75];
mint len[75];
poly p[75][75], tmp[75][75];
mint sum[75][75];
inline poly integ(poly x) {
    x.push_back(0);
    for (int i = x.size(); i --> 1; ) x[i] = x[i - 1] * inv[i];
    x[0] = 0;
    return x;
}
inline poly operator + (poly a, const poly &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) a[i] += b[i];
    return a;
}
inline poly operator - (poly a, const poly &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) a[i] -= b[i];
    return a;
}
inline mint calcsum(poly a, mint x) {
    mint ans, cur = 1;
    for (auto i : a) ans += i * cur, cur *= x;
    return ans;
}
int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        double x;
        scanf("%lf", &x);
        a[i] = round(x * 1000000);
        split[i] = a[i] % 1000000;
    }
    int m = n + 1;
    split[0] = 0, split[n + 1] = 1000000;
    sort(split, split + m + 1);
    m = unique(split, split + m + 1) - split - 1;
    for (int i = 0; i < m; i++) len[i] = (split[i + 1] - split[i]) * mint(1000000).inv();
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            for (int j = 0; j < m; j++) if (split[j + 1] <= a[i]) p[0][j].push_back(1);
        }
        else {
            for (int k = 0; k < n; k++)
                for (int j = 0; j < m; j++) tmp[k][j] = integ(p[k][j]), sum[k][j] = calcsum(tmp[k][j], len[j]), p[k][j].clear();
            for (int k = 0; k < n; k++)
                for (int j = 0; j < m; j++) {
                    if (k * 1000000 + split[j + 1] <= a[i]) {
                        p[k][j] = tmp[k][j];
                        if (k) p[k][j] = p[k][j] - tmp[k - 1][j];
                        if (p[k][j].empty()) p[k][j].resize(1);
                        for (int t = 0; t < j; t++) p[k][j][0] += sum[k][t];
                        if (k) for (int t = j; t < m; t++) p[k][j][0] += sum[k - 1][t];
                    }
                }
        }
    }
    mint ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) ans += calcsum(integ(p[i][j]), len[j]);
    cout << (int)ans << endl;
}