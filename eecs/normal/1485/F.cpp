#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int T, n;
map<long long, int> mp;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), mp.clear();
        long long tag = 0;
        int sum = mp[0] = 1;
        for (int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            int &t = mp[-tag];
            tag += a;
            sum = (sum - t + P) % P;
            t = (1LL * t + sum + P) % P;
            (sum += t) %= P;
        }
        printf("%d\n", sum);
    }
    return 0;
}