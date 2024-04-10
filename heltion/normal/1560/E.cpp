#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        string t;
        cin >> t;
        string d;
        map<char, int> mp;
        for (int i = (int)t.size() - 1; i >= 0; i -= 1) {
            if (not mp.count(t[i])) d = t[i] + d;
            mp[t[i]] += 1;
        }
        int sum = 0, ok = 1;
        for (int i = 0; i < (int)d.size(); i += 1) {
            if (mp[d[i]] % (i + 1)) ok = 0;
            sum += mp[d[i]] / (i + 1);
        }
        string s = t.substr(0, sum);
        string tt = "";
        set<int> st;
        for (int i = 0; i < (int)d.size(); i += 1) {
            for (char c : s) if (not st.count(c)) tt += c;
            st.insert(d[i]);
        }
        if (ok and tt == t)
            cout << s << " " << d << "\n";
        else cout << "-1\n";
    }
    return 0;
}