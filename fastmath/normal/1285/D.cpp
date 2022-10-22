#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int INF = 1e18 + 7;
int solve(vector <int> a, int b) {
    if (a.empty() || b == -1)
        return 0;

    vector <int> v[2];
    for (int e : a) {
        v[(e >> b) & 1].app(e);
    }   
    if (v[0].empty())
        return solve(v[1], b - 1);
    if (v[1].empty())
        return solve(v[0], b - 1);
    return min(solve(v[0], b - 1), solve(v[1], b - 1)) + (1 << b);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve(a, 30) << endl;            
}