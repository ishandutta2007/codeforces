#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

vector<int> get(vector<int> a) {
    int mx = a[0];
    for(auto x : a)
        mx = max(mx, x);

    for(int i = 0; i < a.size(); i++)
        a[i] = mx - a[i];

    return a;
}

void solve() {
    int n;
    li k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans = get(a);
    if(k % 2 == 0)
        ans = get(ans);

    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}