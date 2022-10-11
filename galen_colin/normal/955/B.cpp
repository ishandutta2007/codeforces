#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int cnt[26]={};
    for (auto c : s) cnt[c-'a']++;

    int pos = 0;
    for (auto c : cnt) if (c) pos++;

    if (pos > 4) {
        cout << "No\n";
        return;
    }

    vector<int> v;
    for (int i = 0; i < 26; i++) {
        cnt[i] = min(cnt[i], 2);
        while (cnt[i]--) v.push_back(i);
    }
    int m = sz(v);
    for (int i = 0; i < (1<<m); i++) {
        int one[26]={};
        int two[26]={};
        for (int j = 0; j < m; j++) {
            if ((i>>j)&1) one[v[j]]++;
            else two[v[j]]++;
        }

        int cnt_one = 0;
        int cnt_two = 0;
        for (int i = 0; i < 26; i++) {
            cnt_one += bool(one[i]);
            cnt_two += bool(two[i]);
        }
        if (cnt_one == 2 && cnt_two == 2) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}