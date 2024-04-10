#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mod = 998244353;
vector<int> a, nia;

int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}

int sub(int x, int y) {
    x -= y;
    return x < 0 ? x + mod : x;
}

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}

void pre(int n) {
    a = vector<int>(n + 1, 1);
    nia = vector<int>(n + 1, 1);
    for (int i = 2; i <= n; i++)
        a[i] = mul(a[i - 1], i);
    nia[n] = calc(a[n], mod - 2);
    for (int i = n - 1; i >= 2; i--)
        nia[i] = mul(nia[i + 1], (i + 1));
}

int C(int x, int y) {
    if (x < y || y < 0) return 0;
    return mul(mul(a[x], nia[y]), nia[x - y]);
}
int DB(int x, int y) {
    return C(x + y, x);
}
int get(int n, int as, int B, int A, int sumB, int sumA) {
    int v1 = (A >= as ?mul(mul(C(A - 1, as), mul(a[as], a[A - as])), mul(sumA, nia[A])): 0);
    int v2 = (A >= as && B >= 1 ? mul(mul(mul(mul(mul(DB(A + 1, B - 1), a[B - 1]), mul(mul(a[A - as], a[as]), (A - as + 1))), C(A, as)), nia[n]), sumB): 0);
    return add(v1, v2);
}
int n ,m;
const int N = 1e6;
int A[N], sum[N], all;
int main(){
    pre(1000000);
    scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]), all = add(A[i] % mod, all);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i ++)
        sum[i] = add(sum[i - 1], A[i] % mod);
    while (m --) {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = lower_bound(A + 1, A + n + 1, b) - A;
        printf("%d\n", get(n, a, x - 1, n - x + 1, sum[x - 1], sub(all, sum[x - 1])));
    }
    return 0;
}