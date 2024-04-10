#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn], cs[maxn], ch[maxn];
long long ans;
string s, t[maxn];

bool comp(int i, int j) {
    return 1LL * cs[i] * t[j].length() > 1LL * cs[j] * t[i].length();
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i], p[i] = i;
        for (char j : t[i]) {
            if (j == 's') cs[i]++;
            else ch[i]++;
        }
    }
    sort(p + 1, p + n + 1, comp);
    for (int i = 1; i <= n; i++) {
        for (char j : t[p[i]]) {
            s.push_back(j);
        }
    }
    for (int i = 0, j = 0; i < s.length(); i++) {
        if (s[i] == 's') j++;
        else ans += j;
    }
    printf("%lld\n", ans);
    return 0;
}