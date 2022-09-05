#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1000010;
int n, cur[maxn];
bool pr[maxn], mark[maxn];
ull h[maxn], pre[maxn];
vector<int> ans, V;
mt19937_64 rnd(time(0));
unordered_map<ull, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) if (!pr[i]) {
        for (int j = i + i; j <= n; j += i) pr[j] = 1;
    }
    iota(cur + 1, cur + n + 1, 1);
    for (int i = 2; i <= n; i++) if (!pr[i]) {
        long long k = 1LL * i * i;
        for (long long j = k; j <= n; j += k) {
            while (!(cur[j] % k)) cur[j] /= k;
        }
        ull val = rnd();
        for (int j = i; j <= n; j += i) {
            if (!(cur[j] % i)) h[j] ^= val;
        }
    }
    ull all = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] ^ h[i];
        all ^= pre[i], mp[pre[i]] = i;
    }
    if (!all) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) printf("%d ", i);
        exit(0);
    }
    for (int i = 1; i <= n; i++) if (pre[i] == all) {
        printf("%d\n", n - 1);
        for (int j = 1; j <= n; j++) if (i ^ j) printf("%d ", j);
        exit(0);
    }
    for (int i = 1; i <= n; i++) if (mp.count(pre[i] ^ all)) {
        int j = mp[pre[i] ^ all];
        printf("%d\n", n - 2);
        for (int k = 1; k <= n; k++) if (i ^ k && j ^ k) printf("%d ", k);
        exit(0);
    }
    for (int i = n - 2000; i <= n; i++) {
        for (int j = n - 2000; j <= n; j++) if (mp.count(pre[i] ^ pre[j] ^ all)) {
            int k = mp[pre[i] ^ pre[j] ^ all];
            printf("%d\n", n - 3);
            for (int l = 1; l <= n; l++) if (i ^ l && j ^ l && k ^ l) printf("%d ", l);
            exit(0);
        }
    }
    for (int i = n - 2000; i <= n; i++) {
        for (int j = 1; j <= 2000; j++) if (mp.count(pre[i] ^ pre[j] ^ all)) {
            int k = mp[pre[i] ^ pre[j] ^ all];
            printf("%d\n", n - 3);
            for (int l = 1; l <= n; l++) if (i ^ l && j ^ l && k ^ l) printf("%d ", l);
            exit(0);
        }
    }
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) if (mp.count(pre[i] ^ pre[j] ^ all)) {
            int k = mp[pre[i] ^ pre[j] ^ all];
            printf("%d\n", n - 3);
            for (int l = 1; l <= n; l++) if (i ^ l && j ^ l && k ^ l) printf("%d ", l);
            exit(0);
        }
    }
    assert(0);
    return 0;
}