#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 80, INF = 5e18;
int dp[N][N];

struct Chel {
    int a, b, i;
};
bool comp(Chel a, Chel b) {
    return a.b < b.b;
}   
void solve() {
    int n, k;
    cin >> n >> k;
    vector <Chel> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b;
        a[i].i = i + 1;
    }
    sort(all(a), comp);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -INF;

    //f - b, s - a
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] == -INF)
                continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (k - 1) * a[i].b);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + j * a[i].b + a[i].a);
        }   
    }   
    vector <bool> us(n);
    int cn = n, ck = k;
    while (cn) {
        if (dp[cn][ck] == dp[cn - 1][ck] + (k - 1) * a[cn - 1].b) {
        }   
        else {
            us[cn - 1] = 1;
            --ck;
        }   
        --cn;
    }   

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (us[i]) {
            ans.app(a[i].i);
        }   
    }   
    int r = ans.back();
    ans.pop_back();

    for (int i = 0; i < n; ++i) {
        if (!us[i]) {
            ans.app(a[i].i);
            ans.app(-a[i].i);
        }   
    }   

    ans.app(r);

    cout << ans.size() << endl;
    for (int e : ans)
        cout << e << ' ';
    cout << endl;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}