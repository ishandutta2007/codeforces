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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3e5 + 7;
int n, m, a[N];
int dist(int a, int b) {
    if (a <= b)
        return b - a;
    else 
        return m - a + b;
}   
bool check(int mid) {
    int mn = 0;
    for (int i = 0; i < n; ++i) {
        if (dist(a[i], mn) <= mid)
            continue;
        if (a[i] < mn)
            return 0;
        else
            mn = a[i];
    }   
    return 1;
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = -1, r = N;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }   
    cout << r << '\n';
}