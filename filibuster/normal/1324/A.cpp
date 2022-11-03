#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }

    for(int i = 1; i < n; i++)
    if(a[i] != a[i - 1]) {
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

}