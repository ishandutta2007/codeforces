#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

long long calc(vector<string> s) {
    long long ans = 0;
    long long tmp = stoi(s[0]);
    for (int i = 1; i < (int) s.size(); i += 2) {
        if (s[i] == "+") {
            ans += tmp;
            tmp = stoll(s[i + 1]);
        } else if (s[i] == "*") {
            tmp *= stoll(s[i + 1]);
        }
    }
    return ans + tmp;
}

long long calc(int l, int r, vector<string> s) { // [l, r)
    vector<string> mid;
    for (int i = l; i < r; ++i) {
        mid.push_back(s[i]);
    }
    vector<string> nw;
    for (int i = 0; i < l; ++i) {
        nw.emplace_back(s[i]);
    }
    nw.push_back(to_string(calc(mid)));
    for (int i = r; i < s.size(); i += 1) {
        nw.emplace_back(s[i]);
    }
    return calc(nw);
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    vector<string> s;
    string tmp;
    cin >> tmp;
    s.push_back("1");
    s.push_back("*");
    for (auto i : tmp) {
        s.push_back("");
        s.back() += i;
    }
    s.push_back("*");
    s.push_back("1");
    vector<int> pos;
    int n = s.size();
    for (int i = 0; i < n; i += 1) {
        if (s[i] == "*")
            pos.push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < (int) pos.size(); ++i) {
        for (int j = i + 1; j < (int) pos.size(); ++j) {
            ans = max(ans, calc(pos[i] + 1, pos[j], s));
        }
    }
    cout << ans << '\n';
}