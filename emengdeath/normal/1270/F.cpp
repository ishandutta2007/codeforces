#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;
const int N  = 1e6;
char s[N];
int sum[N], to[N];
int n, S;
int b[N];
unordered_map<int, int>f;
int did(int x, int s) {
    return sum[x] * s - x;
}

long long work1(int L, int R, int j, int mid){
    if (L > R) return 0;
    return 1ll * (L * j - mid + 1 + R * j - mid + 1) * (R - L + 1)/ 2 ;
}
long long work2(int L, int R, int x) {
    if (L > R ) return 0;
    return 1ll * (R - L + 1) * x;
}
long long work3(int L, int R, int j, int mid, int x) {
    if (L > R) return 0;
    return 1ll * (x - L * j + 1 + x - R * j + 1)* (R - L + 1) / 2 ;
}
int main() {
    scanf("%s", s + 1);
    n = strlen(s +1);
    S = sqrt(n) + 1;
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + (s[i] == '1');
    to[n + 1] = n + 1;
    for (int i = n; i >= 1; i --)
        if (s[i + 1] == '1')
            to[i] = i + 1;
        else
            to[i] = to[i + 1];
    long long ans = 0;
    for (int i = 1; i <= S; i ++) {
        b[0] = did(0, i);
        for (int j = 1; j <= n; j ++)
            b[j] = did(j, i);
        sort(b, b + n + 1);
        int sum = 1;
        for (int i = 1; i <= n; i ++)
            if (b[i] != b[i - 1])
                ans += 1ll * sum * (sum - 1) / 2 , sum = 1;
            else
                sum ++;
        ans += 1ll * sum * (sum- 1) / 2;
    }
    int sum0 = 0;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == '0') {
            sum0 ++;
            continue;
        }
        int x = i;
        for (int j = 1; j <= S; j ++) {
            int sum0_r = to[x] - x - 1;
            int mid = x - i + 1;
            int L = max(((x - i) + 1 + j - 1) / j, S + 1);
            int R = ((x - i) + 1 + sum0 + sum0_r) / j;
            if (R >= L) {
                int x = min(sum0, sum0_r), y = max(sum0, sum0_r);
                ans += work1(L, min((mid + x) / j, R), j, mid);
                ans += work2(max((mid + x) / j + 1, L), min((mid + y) / j,R), x + 1);
                ans += work3(max((mid + y)/ j + 1, L), R, j, mid, x + y + mid);
            }
            if (to[x] > n) break;
            x = to[x];
        }
        sum0 = 0;
    }
    printf("%lld\n", ans);
    return 0;
}