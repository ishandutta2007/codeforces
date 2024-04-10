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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

const int N = 1e5+7;
int pref[N][2], suff[N][2];
int l[N][2], r[N][2];
int cost[2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;

    cin >> cost[0] >> cost[1];

    int n = s.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j)
            pref[i + 1][j] = pref[i][j];
        if (s[i] != '?') {
            pref[i + 1][s[i]-'0']++;
        }
    }   

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j)
            suff[i][j] = suff[i + 1][j];
        if (s[i] != '?') {
            suff[i][s[i]-'0']++;
        }
    }   

    int add = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            add += cost[1] * pref[i][1];
        }   
        else if (s[i] == '1') {
            add += cost[0] * pref[i][0];
        }   
    }   

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            l[i + 1][j] = l[i][j];
            if (s[i] == '?') {
                l[i + 1][j] += cost[j ^ 1] * pref[i][j ^ 1];
            }
            else if (s[i] - '0' != j) {
                l[i + 1][j] += cost[j] * cur;
            }
        }   
        cur += s[i] == '?';
    }   

    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j) {
            r[i][j] = r[i + 1][j];
            if (s[i] == '?') {
                r[i][j] += cost[j] * suff[i + 1][j ^ 1];
            }   
            else if (s[i] - '0' != j) {
                r[i][j] += cost[j ^ 1] * cur;
            }   
        }   
        cur += s[i] == '?';
    }   

    int L = 0;
    int R = cur;
    int ans = 1e18;
    for (int i = 0; i <= n; ++i) {
        for (int t = 0; t < 2; ++t) {

            /*
            if (i == 0 && t == 0) {
                debug(l[i][t]);
                debug(r[i][t ^ 1]);
                debug(L * R * cost[t]);
                exit(0);
            }
            */
            
            ans = min(ans, l[i][t] + r[i][t ^ 1] + L * R * cost[t] + L * suff[i][t ^ 1] * cost[t] + pref[i][t] * R * cost[t]);
        }
        if (i < n && s[i] == '?') {
            L++;
            R--;
        }   
    }   
    cout << ans + add << endl;
}