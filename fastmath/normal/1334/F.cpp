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

const int N = 5e5 + 7, INF = 1e18;
int n, m, a[N], b[N], p[N], dp[N];

struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    return get(r) - get(l - 1);
}   
} f, fmn;
int tot = 0;

/*
int get(int pref, int x) {
    int ans = 0;
    for (int i = 0; i < pref; ++i) {
        if (a[i] <= x)
            ans += min(0ll, p[i]);
        else
            ans += p[i];
    }   
    return ans;        
}
*/
vector <int> c;
void addi(int i) {
    tot += p[i];

    int pos = lower_bound(all(c), a[i]) - c.begin();

    f.add(pos, p[i]);
    fmn.add(pos, min(0ll, p[i]));
}   
int get(int x) {
    int r = upper_bound(all(c), x) - c.begin() - 1;
    return fmn.get(r) + (tot - f.get(r));
}     

int cur[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    a[n] = INF;
    ++n;

    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    b[m] = INF;
    ++m;

    for (int i = 0; i < n; ++i)
        c.app(a[i]);
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());

    for (int i = 0; i < N; ++i)
        cur[i] = INF;
    for (int i = 0; i < n; ++i) {
        int pb = lower_bound(b, b + m, a[i]) - b;
        if (b[pb] != a[i]) {
            addi(i);
            dp[i] = INF;
            continue;
        }   
        if (pb == 0) {
            dp[i] = get(0);
            addi(i);
            cur[pb] = min(cur[pb], dp[i] - get(a[i]));            
        }   
        else {
            int x = b[pb - 1];
            int add = get(x);
            addi(i);
            dp[i] = INF;
            if (cur[pb - 1] != INF) {
                dp[i] = cur[pb - 1] + add;
                cur[pb] = min(cur[pb], dp[i] - get(a[i]));
            }
        }   

        #ifdef HOME
        cout << i << ' ' << dp[i] << endl;
        #endif
    }   
    
    if (dp[n - 1] == INF)
        cout << "NO" << endl;
    else
        cout << "YES" << endl << dp[n - 1] << endl;
}