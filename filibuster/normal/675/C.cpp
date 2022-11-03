#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<li> s(n + 1, 0);
    map<li, int> mp;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
        mp[s[i]]++;
    }

    int ans = 1;
    for(auto p : mp)
        ans = max(ans, p.s);

    cout << n - ans << endl;
}