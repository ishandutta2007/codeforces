#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    unordered_set<string> store;
    vector<vector<vector<int>>> used(2, vector<vector<int>>(26, vector<int>(26, 0)));
    for (int test = 1; test <= ttt; ++test) {
        bool good = false;
        int n;
        cin >> n;
        string s;
        store.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s;
            store.insert(s);
            if (store.find(string(s.rbegin(), s.rend())) != store.end()) {
                good = true;
                continue;
            }
            int len = s.size();
            if (used[3 - len][s[len - 1] - 'a'][s[len - 2] - 'a'] == test) {
                good = true;
                continue;
            }
            used[len - 2][s[0] - 'a'][s[1] - 'a'] = test;
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}