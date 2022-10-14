#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct SegTree {
private:
    vll mx, lz;
    int n;

    void push(int v) {
        if(!lz[v]) return;
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
        mx[v*2]+=lz[v];
        mx[v*2+1]+=lz[v];
        lz[v]=0;
    }

    void upd(int ql, int qr, ll val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            mx[v]+=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            mx[v]=max(mx[v*2], mx[v*2+1]);
        }
    }

    ll get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return LLONG_MIN;
        if(ql<=l&&qr>=r) return mx[v];
        else {
            push(v);
            int m=(l+r)/2;
            return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }

public:
    SegTree(int n): n(n), mx(4*n+4, 0), lz(4*n+4, 0){}
    void upd(int ql, int qr, ll val) {upd(ql, qr, val, 1, 0, n-1);}
    ll get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        if(s < t) {cout << "0\n"; continue;}
        string ss = s; sort(all(ss));
        if(ss >= t) {cout << "-1\n"; continue;}
        int lst[26];
        rep(i, n) lst[ss[i] - 'a'] = i;
        rep1(i, 25) lst[i] = max(lst[i], lst[i - 1]);
        vector<int> pos[26];
        rep(i, n) pos[s[i] - 'a'].pb(i);
        rep(i, 26) reverse(all(pos[i]));
        SegTree tr(n);
        ll ans = LLONG_MAX, cur = 0;
        for(int i = 0; i < n; i++) {
            char si = '#';
            rep(j, 26) if(!pos[j].empty()) {
                int x = pos[j].back();
                if(x + tr.get(x, x) == i) {
                    si = j + 'a';
                    break;
                }
            }
            assert(si != '#');
            if(si < t[i]) {
                ans = min(ans, cur);
                break;
            }
            if(i == n - 1) break;
            if(si == t[i]) {
                for(int c = t[i] - 'a' - 1; ~c; c--) if(!pos[c].empty()) {
                    int j = pos[c].back();
                    j += tr.get(j, j);
                    ans = min(ans, cur + j - i);
                }
                pos[t[i] - 'a'].pop_back();
            }
            else {
                for(int c = t[i] - 'a' - 1; ~c; c--) if(!pos[c].empty()) {
                    int j = pos[c].back();
                    j += tr.get(j, j);
                    ans = min(ans, cur + j - i);
                }
                if(pos[t[i] - 'a'].empty()) break;
                else {
                    int j = pos[t[i] - 'a'].back(), k = j;
                    j += tr.get(j, j);
                    cur += j - i;
                    tr.upd(0, k, 1);
                    pos[t[i] - 'a'].pop_back();
                }
            }
        }
        cout << ans << endl;
    }
}