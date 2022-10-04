#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void print(vector <pair <int, int>> ans) {
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    vector <pair <int, int>> kek;
    kek.emplace_back(xa, ya);
    kek.emplace_back(xb, yb);
    kek.emplace_back(xc, yc);
    sort(kek.begin(), kek.end());
        
    vector <pair <int, int>> ans;
    ans.push_back(kek[0]);
    ans.push_back(kek[1]);
    ans.push_back(kek[2]);
    auto p = kek[1];
    while (kek[1].second != kek[0].second) {
        ans.push_back(kek[1]);
        if (kek[1].second < kek[0].second) ++kek[1].second;
        else --kek[1].second;
    }
    while (kek[1] != kek[0]) {
        ans.push_back(kek[1]);
        if (kek[1].first < kek[0].first) ++kek[1].first;
        else --kek[1].first;
    }
    kek[1] = p;
    while (kek[1].second != kek[2].second) {
        ans.push_back(kek[1]);
        if (kek[1].second < kek[2].second) ++kek[1].second;
        else --kek[1].second;
    }
    while (kek[1] != kek[2]) {
        ans.push_back(kek[1]);
        if (kek[1].first < kek[2].first) ++kek[1].first;
        else --kek[1].first;
    }
    print(ans);
}