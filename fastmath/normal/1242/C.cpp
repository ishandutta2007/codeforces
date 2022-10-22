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
const int N = 15;
int n;
map <int, int> box;
vector <int> a[N];
int take[N], s[N];
bool used[N], dp[1 << N], can[1 << N];
int c[1 << N][N], p[1 << N][N];
int ans_c[N], ans_p[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
            s[i] += a[i][j];
            box[a[i][j]] = i;
        }   
    }   
    if (sum % n) {
        cout << "No\n";
        exit(0);
    }   
    int w = sum / n;
    for (int st = 0; st < n; ++st) {
        for (int e : a[st]) {
            memset(used, 0, sizeof used);
            int i = st; take[st] = e; used[i] = 1;
            bool ban = 0;
            while (1) {
                int add = w - (s[i] - take[i]);
                if (box.find(add) == box.end()) {
                    ban = 1;
                    break;
                }
                i = box[add];
                if (i == st) {
                    if (add != e) ban = 1;
                    break;
                }
                if (used[i]) {
                    ban = 1;
                    break;
                }   
                used[i] = 1;
                take[i] = add;
            }               
            if (!ban) {
                int mask = 0;
                for (int i = 0; i < n; ++i) if (used[i]) mask += 1 << i;
                dp[mask] = 1; can[mask] = 1;
                int i = st;
                while (1) {
                    int add = w - (s[i] - take[i]);
                    int mem = i;
                    i = box[add];
                    c[mask][i] = add; p[mask][i] = mem;
                    if (i == st) break;
                }   
            }   
        }
    }   
    dp[0] = 1;
    for (int m = 1; m < (1 << n); ++m) {
        for (int s=m; s; s=(s-1)&m) dp[m] |= dp[s] && dp[m - s];
    }   
    if (dp[(1 << n) - 1]) {
        cout << "YES\n";
        int m = (1 << n) - 1;
        while (m) {
            for (int s=m; s; s=(s-1)&m) {
                if (can[s] && dp[m - s]) {
                    for (int i = 0; i < n; ++i) {
                        if ((s >> i) & 1) {
                            ans_c[i] = c[s][i];
                            ans_p[i] = p[s][i];
                        }   
                    }   
                    m -= s;
                    break;
                }   
            }   
        }   
        for (int i = 0; i < n; ++i) cout << ans_c[i] << ' ' << ans_p[i] + 1 << '\n';
    }
    else cout << "NO\n";
}