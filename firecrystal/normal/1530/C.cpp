// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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

const int N = 3e5 + 5;

int n, a[N], b[N];

bool inline check(int x) {
    vector<int> A, B;
    for (int i = 1; i <= n; i++) A.pb(a[i]);
    for (int i = 1; i <= n; i++) B.pb(b[i]);
    for (int i = 1; i <= x; i++) A.pb(100), B.pb(0);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sa = 0, sb = 0;
    int k = A.size(), l = k / 4;
    int t = A.size();
    for (int i = 0; i < k - l; i++) {
        --t;
        sa += A[t], sb += B[t];
    }
    return sa >= sb;
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) read(b[i]);
        int l = 0, r = n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", r);
    }
    return 0;
}