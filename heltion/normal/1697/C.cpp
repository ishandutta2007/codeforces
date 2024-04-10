#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    for (cin >> q; q; q -= 1) {
        cout << ([](){
            int n;
            string s, t;
            cin >> n >> s >> t;
            map<int, set<int>> mp = {{'a', {n}}, {'b', {n}}, {'c', {n}}};
            for (int i = 0; i < n; i += 1)
                mp[s[i]].insert(i);
            for (char c : t) {
                if (mp[c].size() == 1) return false;
                int i = *mp[c].begin();
                mp[c].erase(mp[c].begin());
                if (c == 'a' and i > min(*mp['b'].begin(), *mp['c'].begin()))
                    return false;
                if (c == 'b' and i > *mp['c'].begin())
                    return false;
                if (c == 'c' and i > *mp['a'].begin())
                    return false;
            }
            return true;
        }() ? "YES\n" : "NO\n");
    }
    return 0;
}