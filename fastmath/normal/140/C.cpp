#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

struct Snowman {
    vector <int> v;
    Snowman(vector <int> v_) {
        v = v_;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }
};

vector <Snowman> ans;
int b[MAXN], val[MAXN];

struct Comp {
    bool operator ()(const int i, const int j) const {
        return (b[i] < b[j]) || (b[i] == b[j] && i < j);
    }
};  

void solve() {
    map <int, int> d;
    for (int i = 0; i < n; ++i) ++d[a[i]];
    int u = 0;
    for (auto e : d) {
        b[u] = e.second;
        val[u] = e.first;
        ++u;
    }
    n = u;
    set <int, Comp> ms;
    for (int i = 0; i < n; ++i) ms.insert(i);
    while (ms.size() && b[*ms.begin()] == 0) ms.erase(ms.begin());
    while (ms.size() >= 3) {
        auto it1 = ms.end(); --it1;
        auto it2 = it1; --it2;
        auto it3 = it2; --it3;

        int i = *it1, j = *it2, k = *it3;
        ms.erase(i); ms.erase(j); ms.erase(k);
        --b[i]; --b[j]; --b[k];
        ans.push_back(Snowman({val[i], val[j], val[k]}));
        ms.insert(i); ms.insert(j); ms.insert(k);

        while (ms.size() && b[*ms.begin()] == 0) ms.erase(ms.begin());
    }
}

void print() {
    cout << ans.size() << '\n';
    for (auto e : ans) {
        for (int ne : e.v) cout << ne << ' ';
        cout << '\n';
    }
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print(); 

    return 0;
}