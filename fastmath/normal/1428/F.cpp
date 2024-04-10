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
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 5e5+7;

int n;
string s;

int mx[N];
int sum[N];
int pref[N], suff[N];

int ans = 0;
void solve(int l, int r) {

    if (l == r) {
        if (s[l] == '1')
            ans++;
        return;            
    }   

    int m = (l + r) >> 1;
    solve(l, m);
    solve(m + 1, r);

    {
    int cur = 0;
    int b = 0;
    int sm = 0;
    suff[m + 1] = 0;
    for (int i = m; i >= l; --i) {
        if (s[i] == '1')
            cur++;
        else
            cur = 0;
        b = max(b, cur);
        mx[i] = b;                
        sm += b;
        suff[i] = sm;
    }   
    }

    {
    int cur = 0;
    int b = 0;
    pref[m] = 0;
    int sm = 0;
    for (int i = m + 1; i <= r; ++i) {
        if (s[i] == '1')
            cur++;
        else
            cur = 0;
        b = max(b, cur);
        sm += b;
        mx[i] = b;
        pref[i] = sm;
    }   
    }

    int L = 0;
    while (m - L >= l && s[m - L] == '1') {
        L++;
    }   
    int R = 0;
    while (m + 1 + R <= r && s[m + 1 + R] == '1') {
        R++;
    }   

    int M = L + R;

    /*
    for (int i = m; i >= l; --i) {
        for (int j = m + 1; j <= r; ++j) {
            int l1 = min(L, mx[i]);
            int r1 = min(R, mx[j]);
            ans += max({l1 + r1, mx[i], mx[j]});
        }   
    }
    */

    for (int i = m; i >= l; --i) {
        if (mx[i] < L) {
            ans += R * mx[i] + sum[R];                                                
            int x = mx[i] + R;
            int p = upper_bound(mx + m + 1, mx + r + 1, x) - mx;
            ans += (p - 1 - m - R) * x;
            ans += pref[r] - pref[p - 1];
        }   
        else {
            if (M <= mx[i]) {
                int p = upper_bound(mx + m + 1, mx + r + 1, mx[i]) - mx;
                ans += (p - 1 - m) * mx[i];
                ans += pref[r] - pref[p - 1];
            }   
            else {
                int was = ans;

                assert(mx[i] >= L);
                int w = mx[i] - L + 1;
                ans += (w - 1) * mx[i];
                ans += sum[M] - sum[mx[i]];
                int p = upper_bound(mx + m + 1, mx + r + 1, M) - mx;

                // w..p-1-m : mx[i] + 1..
                
                assert(p == r + 1 || p - 1 - m >= R + 1);
                int len = (p - 1 - m) - (R + 1) + 1;
                ans += len * M;
                ans += pref[r] - pref[p - 1];
            }   
        }   
    }
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    for (int i = 1; i < N; ++i)
        sum[i] = sum[i - 1] + i;

    cin >> n;
    cin >> s;
    solve(0, n - 1);
    cout << ans << endl;

    #ifdef HOME
    cout << Time << endl;
    #endif
}