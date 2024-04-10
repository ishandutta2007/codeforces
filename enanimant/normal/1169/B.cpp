// May 26, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > v;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        s.insert(a);
        s.insert(b);
    }
    if (s.size() <= 3) {
        cout << "YES\n";
        return 0;
    }
    vector< vector<int> > w(2, vector<int>(2));
    w[0][0] = v[0].first;
    w[0][1] = v[0].second;
    w[1][0] = v[1].first;
    w[1][1] = v[1].second;
    for (int i = 1; i < m; i++) {
        if (v[i].first != v[0].first && v[i].first != v[0].second
                && v[i].second != v[0].first && v[i].second != v[0].second) {
            w[1][0] = v[i].first;
            w[1][1] = v[i].second;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int a = w[0][i], b = w[1][j];
            bool works = true;
            for (auto p : v) {
                works &= (p.first == a || p.second == a || p.first == b || p.second == b);
            }
            if (works) {
                cout << "YES\n";
                // cerr << a << ' ' << b << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";


    return 0;
}