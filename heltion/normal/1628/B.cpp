#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1){
        int n, ok = 0;
        cin >> n;
        vector<string> vs(n);
        set<string> st, s23, s32;
        for (auto& s : vs) {
            cin >> s;
            auto t = s;
            ranges::reverse(t);
            if (st.count(t)) ok = 1;
            if (t == s) ok = 1;
            st.insert(s);
            if (s.size() == 2) {
                s23.insert(t);
                if (s32.count(t)) ok = 1;
            }
            if (s.size() == 3) {
                s32.insert(s.substr(0, 2));
                if (s23.count(s.substr(1))) ok = 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}