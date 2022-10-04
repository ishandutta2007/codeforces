#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string A = "aeiouy";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    string t;
    getline(cin, t);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int cnt = 0;
        for (auto c : s) {
            if (A.find(c) != -1) ++cnt;
        }
        if (cnt != p[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}