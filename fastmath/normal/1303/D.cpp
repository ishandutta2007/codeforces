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

int get(int n) {
    int p = 0, v = 1;
    while (v != n) {
        ++p;
        v <<= 1;
    }   
    return p;
}   

const int LG = 61;
int cnt[LG];

void solve() {
    for (int i = 0; i < LG; ++i)
        cnt[i] = 0;
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[get(x)];
    }   
    int ans = 0;
    int have = 0;
    for (int i = 0; i < LG; ++i) {
        have += cnt[i];
        if ((w >> i) & 1) {
            if (!have) {
                for (int j = i + 1; j < LG; ++j) {
                    if (cnt[j]) {
                        ans += j - i;
                        --cnt[j];
                        for (int k = j - 1; k > i; --k) {
                            ++cnt[k];
                        }   
                        have += 2;
                        break;
                    }   
                }   
                if (!have) {
                    cout << -1 << endl;
                    return;
                }   
            }   
            --have;
        }   
        have >>= 1;
    }   
    cout << ans << endl;
}

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
        solve();
    }   
}