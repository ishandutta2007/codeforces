#include<bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    auto t = s;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    map <char, int> cnt;
    for (char c : s) ++cnt[c];
    if (4 <= t.size()) {
        for (int i = 1; i < (int)t.size(); i += 2) {
            for (int j = 0; j < cnt[t[i]]; ++j) cout << t[i];
        }
        for (int i = 0; i < (int)t.size(); i += 2) {
            for (int j = 0; j < cnt[t[i]]; ++j) cout << t[i];
        }
        cout << '\n';
    }   
    else if (t.size() == 3) {
        if (t[1] == t[0] + 1 && t[2] == t[1] + 1) {
            cout << "No answer\n";
        }   
        else {
            if (t[0] + 1 != t[1]) {
                for (int i = 0; i < cnt[t[1]]; ++i) cout << t[1];
                for (int i = 0; i < cnt[t[0]]; ++i) cout << t[0];
                for (int i = 0; i < cnt[t[2]]; ++i) cout << t[2];
                cout << '\n';
            }
            else {
                for (int i = 0; i < cnt[t[1]]; ++i) cout << t[1];
                for (int i = 0; i < cnt[t[2]]; ++i) cout << t[2];
                for (int i = 0; i < cnt[t[0]]; ++i) cout << t[0];
                cout << '\n';
            }   
        }   
    }
    else if (t.size() == 2) {
        if (t[0] + 1 == t[1]) {
            cout << "No answer\n";
        }   
        else {
            for (int i = 0; i < cnt[t[0]]; ++i) cout << t[0];
            for (int i = 0; i < cnt[t[1]]; ++i) cout << t[1];            
            cout << '\n';
        }   
    }
    else {
        cout << s << '\n';
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) solve();

}