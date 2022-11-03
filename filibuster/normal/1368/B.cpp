#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;

void solve() {
    li n;
    cin >> n;

    string s = "codeforces";

    vector<int> a(s.length(), 1);
    li res = 1;

    while(res < n) {
        int mn = 0;
        for(int i = 1; i < a.size(); i++)
            if(a[mn] > a[i])
                mn = i;

        a[mn]++;

        res = 1;

        for(int i = 0; i < a.size(); i++)
            res *= a[i];
    }

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i]; j++)
            cout << s[i];
    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}