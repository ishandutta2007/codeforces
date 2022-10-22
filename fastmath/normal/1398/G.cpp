#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 2e5+7, C = 1e6+7;
int n, X, Y;
int ans[C];
bool can[C];

bitset <N> ba, c;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < C; ++i)
        ans[i] = -1;
    cin >> n >> X >> Y;
    vector <int> a(n+1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        ba[a[i]] = 1;
    }
                        
    for (int i = 0; i < n; ++i) {
        c |= ba >> a[i];
    }   
    c[0] = 0;
    for (int i = Y; i < C && i - Y < N; ++i)
        can[i] = c[i - Y];

    for (int i = 1; i < C; ++i)
        if (can[i])
            for (int j = i; j < C; j += i)
                ans[j] = i;
    int q;
    cin >> q;
    while (q--) {
        int l;
        cin >> l;
        if (ans[l/2]==-1)
            cout << -1 << ' ';
        else
            cout << ans[l/2]*2 << ' ';
    }   
    cout << endl;
}