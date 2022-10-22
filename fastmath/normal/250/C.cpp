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

const int N = 1e5 + 7;
int n, k;
int a[N];
vector <int> pos[N];
int cnt[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].app(i);
    }
    int all = 0;
    for (int i = 1; i + 1 <= n; ++i) {
        if (a[i] != a[i + 1]) {
            ++all;
            ++cnt[a[i]];
            ++cnt[a[i + 1]];
        }   
    }
    ii ans = mp(N, N);
    for (int i = 1; i <= k; ++i) {
        int c = all - cnt[i];
        int ptr = 0;
        while (ptr < pos[i].size()) {
            int l = ptr, r = ptr;
            for (; r + 1 < pos[i].size() && pos[i][r + 1] == pos[i][r] + 1; ++r) {
                
            }   
            c += (pos[i][l] > 1) && (pos[i][r] < n) && (a[pos[i][l] - 1] != a[pos[i][r] + 1]);
            ptr = r + 1;
        }   
        ans = min(ans, mp(c, i));
    }   
    cout << ans.s << endl;
}