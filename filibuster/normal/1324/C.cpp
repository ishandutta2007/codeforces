#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;

    int n  = s.size();
    int a = -1;int ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            ans = max(ans, i - a);
            a = i;
        }
    }

    cout<< max(ans, n - a) << endl;

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

}