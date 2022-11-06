#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef long long ll;

const int ms = 2e5+5;



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> w = v;
        sort(w.begin(), w.end());
        if(v == w) {
            cout << 0 << endl;
        } else if(v[0] == w[0] || v[n-1] == w[n-1]) {
            cout << 1 << endl;
        } else if(v[0] != w[n-1] || w[0] != v[n-1]) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
    return 0;
}