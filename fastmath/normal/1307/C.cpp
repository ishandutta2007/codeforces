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
string s;
int cnt[C][C], cur[C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        for (int i = 0; i < C; ++i)
            cnt[i][c] += cur[i];
        ++cur[c];
    }   
    int ans = 0;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            ans = max(ans, cnt[i][j]);
    for (int i = 0; i < C; ++i)
        ans = max(ans, cur[i]);
    cout << ans << '\n';
}