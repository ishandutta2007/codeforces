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
const int N = 1e5 + 7;
int w[N], a[N], r[N], n;
bool check(int *ans, int m) {
    for (int i = 0; i < N; ++i)
        a[i] = r[i] = 0;
    for (int i = 0; i < m; ++i)
        r[i] = ans[i];
    reverse(r, r + m);
    for (int i = 0; i < N; ++i)
        a[i] = ans[i] + r[i];
    for (int i = 0; i < N; ++i)
        if (a[i] && i >= n)
            return 0;
    int add = 0;
    for (int i = 0; i < n; ++i) {
        a[i] += add;
        add = a[i] / 10;
        a[i] %= 10;
    }   
    if (add)
        return 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != w[i])
            return 0;
    return 1;
}   
char next(char c) {
    if (c == '9') return '0';
    else return c + 1;
}
char prev(char c) {
    if (c == '0') return '9';
    else return c - 1;
}   
char f(char c, bool add) {
    if (!add)
        return c;
    else 
        return prev(c);
}   
int sum[N], ans[N];
void solve(string s, bool want) {
    for (int i = 0; i < N; ++i) 
        ans[i] = 0;
    int n = s.size();
    bool add = 0;
    for (int i = 0; i < n / 2; ++i) {
        int t = f(s[n - 1 - i], add) - '0';
        if (!want || t == 9) 
            sum[i] = t;
        else 
            sum[i] = t + 10;
        add = sum[i] + add > 9;
        want = s[i] != t + '0';
    }   
    for (int i = 0; i < n / 2; ++i) {
        ans[i] = min(9ll, sum[i]);
        ans[n - 1 - i] = sum[i] - ans[i];
    }
    if (n & 1) {   
        sum[n / 2] = 10 * want + s[n / 2] - '0' - add;
        ans[n / 2] = sum[n / 2] >> 1;
    }
    if (ans[0] == 0)
        return;
    reverse(ans, ans + n);
    if (check(ans, n)) {
        reverse(ans, ans + n);
        for (int i = 0; i < n; ++i)
            cout << ans[i];
        cout << '\n';
        exit(0);
    }    
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s; cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        w[i] = s[n - i - 1] - '0';
    solve(s, 0);
    solve(s.substr(1, s.size() - 1), 1);
    cout << "0\n";
}