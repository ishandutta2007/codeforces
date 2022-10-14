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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

constexpr int N = 1e6 + 5;
ull hsh[N];
gp_hash_table<ull, int> pos;
int f[N];
bool excl[N];

int32_t main() {
    fastio;
    for(int i = 2; i * i < N; i++) if(f[i] == 0) {
        for(int j = i * i; j < N; j += i) if(f[j] == 0) f[j] = i;
    }
    for(int i = 2; i < N; i++) {
        if(f[i] == 0) {
            hsh[i] = rng();
            f[i] = i;
        }
        else {
            hsh[i] = hsh[f[i]] ^ hsh[i / f[i]];
        }
    }
    int n; cin >> n;
    if(n <= 3) return puts("1\n1"), 0;
    ull tot = 0;
    for(int i = n; i >= 2; i -= 2) tot ^= hsh[i];
    for(int i = 3; i <= n; i++) hsh[i] ^= hsh[i - 1];
    for(int i = 1; i <= n; i++) pos[hsh[i]] = i;
    int ans = n;
    auto pr = [&]() -> void {
        cout << ans << endl;
        for(int i = 1; i <= n; i++) if(!excl[i]) cout << i << ' ';
        cout << endl;
        exit(0);
    };
    while(1) {
        if(tot == 0) pr();
        if(pos.find(tot) != pos.end()) {
            ans--;
            excl[pos[tot]] = 1;
            pr();
        }
        for(int i = 1; i <= n; i++) if(pos.find(tot ^ hsh[i]) != pos.end()) {
            ans -= 2;
            excl[i] = 1;
            excl[pos[tot ^ hsh[i]]] = 1;
            pr();
        }
        ans--;
        tot ^= hsh[n--];
    }
}