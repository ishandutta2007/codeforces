#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll cnt[26];
ll pairs[26][26];

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; s[i]; ++i) {
        int cur = s[i] - 'a';
        for (int j = 0; j < 26; ++j)
            pairs[j][cur] += cnt[j];
        ++cnt[cur];
        ans = max(ans, (ll)cnt[cur]);
    }
    for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j) {
        ans = max(ans, pairs[i][j]);
    }
    cout << ans << endl;
}