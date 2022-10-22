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

const int N = 50;
ii dp[N];

void solve(int n) {
    int w = n - 1;

    int h = -1;
    for (int i = 0; i < N; ++i) {
        if (dp[i].f <= w && w <= 2 * dp[i].s) {
            h = i;
            break;
        }   
    }   

    if (h == -1) {
        cout << "-1" << endl;
        exit(0);
    }   
    
    //cout << "h " << h << endl;

    int k = 1;
    vector <int> ans;
    for (int i = h; i; --i) {
        //cout << i << ' ' << w << ' ' << k << endl;

        int cap = w - dp[i].s * k;
        int delt = dp[i].s;
        int add = (cap + delt - 1) / delt;                
        ans.app(add);
        k += add;
        w -= k;            
    }   

    int cur = 1, cnt = 1;
    for (int e : ans) {
        cnt += e;
        cur += cnt;        
    }   
    if (cur != n) {
        cout << "LMAO " << n << endl;
        exit(1);
    }   

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

    dp[1] = {1, 1};
    for (int i = 2; i < N; ++i) {
        dp[i] = mp(dp[i - 1].f + 1, 2 * dp[i - 1].s + 1);
    }   

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}