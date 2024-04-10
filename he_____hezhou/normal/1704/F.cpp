#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int n;
char s[500010];
int SG[500010];
void rmain() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (s[i] == 'R') cnt++; else cnt--;
    if (cnt > 0) puts("Alice");
    else if (cnt < 0) puts("Bob");
    if (cnt) return;
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        for (r = l; r < n && s[r + 1] != s[r]; r++);
        ans ^= SG[r - l + 1];
    }
    puts(ans ? "Alice" : "Bob");
}
int mex(vector <int> x) {
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for (int i = 0; i < x.size(); i++) if (x[i] != i) return i;
    return x.size();
}
int main() {
    for (int i = 0; i <= 100; i++) {
        vector <int> cur;
        for (int j = 0; j <= i - 2; j++) cur.push_back(SG[j] ^ SG[i - j - 2]);
        SG[i] = mex(cur);
    }
    for (int i = 101; i <= 500000; i++) SG[i] = SG[i - 34];
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}