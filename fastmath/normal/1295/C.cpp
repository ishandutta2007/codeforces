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
const int N = 1e5 + 7, C = 26;
int nx[N][C];
bool suff[N][C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();

        for (int i = 0; i < C; ++i)
            suff[n][i] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < C; ++j)
                suff[i][j] = suff[i + 1][j];
            suff[i][s[i] - 'a'] = 1;
        }   

        for (int i = 0; i < C; ++i)
            nx[n][i] = -1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < C; ++j)
                nx[i][j] = nx[i + 1][j];
            nx[i][s[i] - 'a'] = i;
        }
        for (int i = 0; i < C; ++i)
            nx[n][i] = nx[0][i];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < C; ++j)
                nx[i][j] = nx[i + 1][j];
            nx[i][s[i] - 'a'] = i;
        }

        int ans = 1;
        int p = 0;          
        for (char c : t) {
            if (!suff[0][c - 'a']) {
                ans = -1;
                break;
            }   
            ans += !suff[p][c - 'a'];
            p = nx[p][c - 'a'] + 1;
        }   
        cout << ans << '\n';
    }   
}