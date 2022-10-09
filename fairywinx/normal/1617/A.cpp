#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

bool check(string s, string t) {
    int it = 0;
    for (auto i : s) {
        if (i == t[it]) {
            ++it;
            if (it == (int) t.size())
                return true;
        }
    }
    return false;
}

void solve() {
    string s, t;
    cin >> s >> t;
    array<int, 3> cnt;
    fill(all(cnt), 0);
    string ot;
    for (auto i : s) {
        if (i <= 'c')
            cnt[i - 'a']++;
        else
            ot += i;
    }
    sort(all(ot));
    string tmp1;
    for (int i = 0; i < cnt[0]; ++i)
        tmp1 += 'a';
    for (int i = 0; i < cnt[1]; ++i)
        tmp1 += 'b';
    for (int i = 0; i < cnt[2]; ++i)
        tmp1 += 'c';
    if (!check(tmp1, t)) {
        cout << tmp1 + ot << '\n';
        return;
    }
    tmp1.clear();
    for (int i = 0; i < cnt[0]; ++i)
        tmp1 += 'a';
    for (int i = 0; i < cnt[2]; ++i)
        tmp1 += 'c';
    for (int i = 0; i < cnt[1]; ++i)
        tmp1 += 'b';
    cout << tmp1 + ot << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}