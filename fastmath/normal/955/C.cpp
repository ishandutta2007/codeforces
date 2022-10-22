#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e6 + 7;
const int INF = 1e18 + 7;

vector <int> a;
set <int> ms;

bool ch(int n) {
    int l = 0;
    int r = 1e9 + 7;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m * m <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return (l * l == n);
}

int get(int n) {
    if (n == 0) return 0;
    
    int l = 0;
    int r = 1e9 + 7;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m * m <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    int res = l;
    
    l = -1;
    r = a.size();
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (a[m] <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }

    return res + (l + 1);
}

int getp(int a, int p) {
    int res = 1;
    for (int i = 0; i < p; ++i) {
        res *= a;
        if (INF < res) return INF;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < MAXN; ++i) {
        int pw = 3;
        while (true) {
            ms.insert(getp(i, pw));
            if (getp(i, pw) > INF / i) break;
            ++pw;
        }
    }
    
    for (int elem : ms) {
        if (!ch(elem)) a.push_back(elem);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << '\n';
    }

    return 0;
}