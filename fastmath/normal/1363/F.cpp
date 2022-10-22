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

bool check(string a, string b) {
    sort(all(a)); sort(all(b));
    return a == b;
}   

const int N = 2007;
int dp[N][N];
int pref_s[N][26], pref_t[N][26];

void upd(int &a, int b) { a = min(a, b); }

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        if (!check(s, t)) {
            cout << -1 << endl;
            continue;
        }   

        reverse(all(s));
        reverse(all(t));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j)
                pref_s[i + 1][j] = pref_s[i][j];
            ++pref_s[i + 1][s[i] - 'a'];

            for (int j = 0; j < 26; ++j)
                pref_t[i + 1][j] = pref_t[i][j];
            ++pref_t[i + 1][t[i] - 'a'];
        }   

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = 1e9;
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i < n && j < n && s[i] == t[j]) {
                    upd(dp[i + 1][j + 1], dp[i][j]);
                }
                if (j < n) {
                    int c = t[j] - 'a';
                    if (pref_s[i][c] > pref_t[j][c]) {
                        upd(dp[i][j + 1], dp[i][j]);
                    }   
                }
                if (i < n) {
                    upd(dp[i + 1][j], dp[i][j] + 1);
                }   
            }   
        }   
        cout << dp[n][n] << endl;
        /*
        int i = 0, j = 0, ans = 0;
        vector <int> cnt(26);
        while (j < n) {
            if (i < n && s[i] == t[j]) {
                ++i;
                ++j;
            }   
            else if (cnt[t[j] - 'a']) {
                --cnt[t[j] - 'a'];
                ++j;                
            }   
            else {
                ++cnt[s[i] - 'a'];
                ++i;
                ++ans;
            }   
        }
        cout << ans << endl;
        */
    }   

}