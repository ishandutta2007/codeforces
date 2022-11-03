#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

    }

    if(b[0] > a[0]) {
        cout << "NO" << endl;
        return ;
    }

    for(int i = 1; i < n; i++) {
        if(b[i] > a[i] || a[i] < a[i - 1] || b[i] < b[i - 1] || b[i] - b[i - 1] > a[i] - a[i - 1]) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}