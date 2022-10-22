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
} f[26];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < 26; ++i)
        f[i].clear();

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; ++i)
        f[s[i] - 'a'].add(i, 1);

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            --p;
            f[s[p] - 'a'].add(p, -1);
            cin >> s[p];                        
            f[s[p] - 'a'].add(p, 1);
        }   
        else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int ans = 0;
            for (int i = 0; i < 26; ++i) {
                ans += f[i].get(l, r) > 0;
            }   
            cout << ans << '\n';
        }   
    }
}