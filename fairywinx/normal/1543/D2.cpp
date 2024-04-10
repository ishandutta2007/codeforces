// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

int k;

vector<int> to(int a) {
    vector<int> res;
    while (a) {
        res.push_back(a % k);
        a /= k;
    }
    return res;
}

int to(vector<int> a) {
    int tmp = 1;
    int ans = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        ans += a[i] * tmp;
        tmp *= k;
    }
    return ans;
}

vector<int> operator+(vector<int> a, vector<int> b) {
    vector<int> res;
    for (int i = 0; i < (int) max(a.size(), b.size()); ++i) {
        int c = 0;
        if (i < (int) a.size())
            c += a[i];
        if (i < (int) b.size())
            c += b[i];
        res.push_back(c % k);
    }
    return res;
}

vector<int> operator-(vector<int> a, vector<int> b) {
    vector<int> res;
    for (int i = 0; i < (int) max(a.size(), b.size()); ++i) {
        int c = 0;
        if (i < (int) a.size())
            c += a[i];
        if (i < (int) b.size())
            c -= b[i];
        res.push_back((c + k) % k);
    }
    return res;
}

void solve() {
    int n;
    cin >> n >> k;
    vector<int> y = to(0);
    int type = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> j = to(i);
        vector<int> v;
        if (type == 0) {
            v = y - j;
            cout << to(y - j) << endl;
        } else {
            v = j + y;
            cout << to(j + y) << endl;
        }
        int res;
        cin >> res;
        if (res == 1) {
            return;
        } else {
            y = v - y;
            type ^= 1;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}