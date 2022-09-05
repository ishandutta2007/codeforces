#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int cnt[26];
ll n, m, ans;
char s[maxn], t[maxn];

int main() {
    scanf("%lld %lld %s %s", &n, &m, s, t);
    int len1 = strlen(s), len2 = strlen(t);
    int g = __gcd(len1, len2);
    for (int i = 0; i < g; i++) {
        memset(cnt, 0, sizeof(cnt));
        int all = 0;
        for (int j = i; j < len1; j += g) cnt[s[j] - 'a']++, all++;
        for (int j = i; j < len2; j += g) ans += all - cnt[t[j] - 'a'];
    }
    printf("%lld\n", n / (len2 / g) * ans);
    return 0;
}