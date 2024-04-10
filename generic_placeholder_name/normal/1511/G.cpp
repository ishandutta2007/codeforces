#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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

constexpr int N=2e5+1;
bitset<N> has;
int v[N];
int sz;

#include <immintrin.h>

int _buf[8];
int xor_sum(const int* __restrict a, const int sub, int n) {
    __m256i s1 = _mm256_setzero_si256();
    __m256i s2 = _mm256_setzero_si256();
    const __m256i _sub = _mm256_set1_epi32(sub);
    for(int k = 0; k + 16 <= n; k += 16) {
        __m256i x1 = _mm256_sub_epi32(_mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + k)), _sub);
        __m256i x2 = _mm256_sub_epi32(_mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + k + 8)), _sub);
        s1 = _mm256_xor_si256(s1, x1);
        s2 = _mm256_xor_si256(s2, x2);
    }
    __m256i buf = _mm256_xor_si256(s1, s2);
    _mm256_store_si256(reinterpret_cast<__m256i*>(_buf), buf);
    int s = 0; rep(i, 8) s ^= _buf[i];
    for(int k = (n / 16) * 16; k < n; k++) s ^= (a[k] - sub);
    return s;
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep(i, n) {
        int x; cin>>x;
        has[x]=has[x]^1;
    }
    rep1(i, m) if(has[i]) v[sz++]=i;
    int q; cin>>q;
    while(q--) {
        int ql, qr; cin>>ql>>qr;
        int l=lower_bound(v, v+sz, ql)-v;
        int r=upper_bound(v, v+sz, qr)-v;
        int s=xor_sum(v+l, ql, r-l);
        cout<<(s?'A':'B');
    }
}