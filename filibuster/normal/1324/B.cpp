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
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i  =0; i < n; i++)
        for(int j = i + 2; j < n; j++)
    if(a[i] == a[j]) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

}