#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<li> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<li, int> mp;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        for(li j = 1; j < 1e12; j *= 2) {
            ans += mp[j - a[i]];
        }

        mp[a[i]]++;
    }

    cout << ans << endl;
}