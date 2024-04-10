#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define x first
#define y second

const int MAXN = 2e5 + 7;

int n;
pair <double, double> a[MAXN];
vector <pair <double, double> > ans;

pair <double, double> vect(pair <double, double> a, pair <double, double> b) {
    return {b.first - a.first, b.second - a.second};
}

double cp(pair <double, double> a, pair <double, double> b) {
    return a.first * b.second - a.second * b.first;
}   

bool comp(int i, int j) {
    return a[i] < a[j];
}

void add(pair <double, double> p) {
    while (2 <= ans.size()) {
        auto prpr = ans[(int)ans.size() - 2];
        auto pr = ans[(int)ans.size() - 1];
        if (cp(vect(prpr, p), vect(prpr, pr)) < 0) {
            ans.pop_back();
        }
        else {
            break;
        }
    }
    while (ans.size() && ans.back() != p && ans.back().x <= p.x && ans.back().y <= p.y) ans.pop_back();
    ans.push_back(p);
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].x = 1 - 1.0 / x; 
        a[i].y = 1 - 1.0 / y;
    }

    set <pair <double, double> > ms;
    for (int i = 0; i < n; ++i) ms.insert(a[i]);
    for (auto e : ms) add(e);
    
    ms.clear();
    for (auto e : ans) ms.insert(e);

    for (int i = 0; i < n; ++i) {
        if (ms.find(a[i]) != ms.end()) cout << i + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}