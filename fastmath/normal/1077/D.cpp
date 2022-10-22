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
const int N = 2e5 + 7;
int a[N], cnt[N], ans[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <ii> mem;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }   
    set <pair <double, int > > ms;
    for (int i = 0; i < N; ++i) {
        if (cnt[i]) {
            ms.insert(mp(cnt[i], i));
        }   
    }   
    for (int i = 0; i < k; ++i) {
        int x = ms.rbegin()->s;
        ms.erase(*ms.rbegin());
        cout << x << ' ';
        --cnt[x];
        ++ans[x];
        ms.insert(mp((double)cnt[x] / (ans[x] + 1), x));
    }   
    cout << '\n';
}