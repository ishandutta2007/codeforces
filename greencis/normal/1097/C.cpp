#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n;
string s;

pair<int, int> get(string s) {
    int mn = 0, cur = 0;
    for (int i = 0; s[i]; ++i) {
        cur += (s[i] == '(' ? 1 : -1);
        mn = min(mn, cur);
    }
    return {mn, cur};
}

int cnt1[500105], cnt2[500105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int zero = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        auto qqq1 = get(s);
        for (int j = 0; s[j]; ++j) s[j] = (s[j] == '(' ? ')' : '(');
        reverse(s.begin(), s.end());
        auto qqq2 = get(s);
        if (qqq1.second == 0) {
            if (qqq1.first == 0)
                ++zero;
            continue;
        }
        if (qqq1.second > 0 && qqq1.first == 0) ++cnt1[qqq1.second];
        if (qqq2.second > 0 && qqq2.first == 0) ++cnt2[qqq2.second];
    }
    ans = zero / 2;
    for (int i = 1; i < 500105; ++i)
        ans += min(cnt1[i], cnt2[i]);
    cout << ans << endl;
}