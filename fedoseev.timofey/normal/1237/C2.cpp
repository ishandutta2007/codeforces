#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> x(n), y(n), z(n);
    map <pair <int, int>, vector <int>> who;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        who[{x[i], y[i]}].push_back(i);
    }
    vector <pair <int, int>> ans;
    vector <int> tk(n);
    for (auto &p : who) {
        sort(p.second.begin(), p.second.end(), [&] (int i, int j) {
            return z[i] < z[j];
        });
        while (p.second.size() >= 2) {
            int a = p.second.back();
            p.second.pop_back();
            int b = p.second.back();
            p.second.pop_back();
            tk[a] = 1;
            tk[b] = 1;
            ans.push_back({a, b});
        }
    }
    map <int, vector <int>> xs;
    for (int i = 0; i < n; ++i) {
        if (!tk[i]) {
            xs[x[i]].push_back(i);
        }
    }
    for (auto &p : xs) {
        sort(p.second.begin(), p.second.end(), [&] (int i, int j) {
            return y[i] < y[j];
        });
        while (p.second.size() >= 2) {
            int a = p.second.back();
            p.second.pop_back();
            int b = p.second.back();
            p.second.pop_back();
            tk[a] = 1;
            tk[b] = 1;
            ans.push_back({a, b});
        }
    }
    vector <int> id;
    for (int i = 0; i < n; ++i) if (!tk[i]) id.push_back(i);
    sort(id.begin(), id.end(), [&] (int i, int j) {
        return x[i] < x[j];
    });
    for (int i = 0; i < (int)id.size(); i += 2) {
        ans.push_back({id[i], id[i + 1]});
    }
    for (auto p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}