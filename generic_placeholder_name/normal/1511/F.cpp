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

constexpr int MOD = 998244353;
constexpr int N = 176;

namespace matmul_helper {
    #include <immintrin.h>

    __attribute__((always_inline)) __m256i _mm256_load_pi32x4(const int *x) {
    	return _mm256_cvtepi32_epi64(_mm_load_si128(reinterpret_cast<const __m128i*>(x)));
    }

    __attribute__((always_inline)) ull _sum(const __m256i& x) {
        __m256i sum1 = _mm256_shuffle_epi32(x, 0x0E);
        __m256i sum2 = _mm256_add_epi64(x, sum1);
        __m128i sum3 = _mm256_extracti128_si256(sum2, 1);
        __m128i sum4 = _mm_add_epi64(_mm256_castsi256_si128(sum2), sum3);
        return _mm_cvtsi128_si64(sum4);
    }

    int dot(const int* __restrict a, const int* __restrict b) {
        static const __m256i msk_lo = _mm256_set_epi32(0, -1, 0, -1, 0, -1, 0, -1);
        __m256i hi = _mm256_setzero_si256(), lo = _mm256_setzero_si256();
        for(int k = 0; k + 16 <= N; k += 16) {
            __m256i s1, s2, s3, s4;
            s1 = _mm256_mul_epi32(_mm256_load_pi32x4((int*)(a + k)), _mm256_load_pi32x4((int*)(b + k)));
            s2 = _mm256_mul_epi32(_mm256_load_pi32x4((int*)(a + k + 4)), _mm256_load_pi32x4((int*)(b + k + 4)));
            s3 = _mm256_mul_epi32(_mm256_load_pi32x4((int*)(a + k + 8)), _mm256_load_pi32x4((int*)(b + k + 8)));
            s4 = _mm256_mul_epi32(_mm256_load_pi32x4((int*)(a + k + 12)), _mm256_load_pi32x4((int*)(b + k + 12)));
            lo = _mm256_add_epi64(lo, _mm256_add_epi64(_mm256_add_epi64(s1, s2), _mm256_add_epi64(s3, s4)));
            hi = _mm256_add_epi64(hi, _mm256_srli_epi64(lo, 32));
            lo = _mm256_and_si256(lo, msk_lo);
        }
        ull sum_lo = _sum(lo);
        ull sum_hi = _sum(hi);
        ull res = (sum_lo + (ull(sum_hi % MOD) << 32)) % MOD;
        //for(int k = (n / 16) * 16; k < n; k++) res += a[k] * 1ULL * b[k];
        //N % 16 == 0, no need
        return res % MOD;
    }

};

struct Matrix {
    int a[N][N];
    int rev[N][N];

    Matrix() {
        memset(a, 0, sizeof(a));
        memset(rev, 0, sizeof(rev));
    }

    __attribute__((always_inline)) void set(int i, int j, int x) {
        a[i][j] = x;
        rev[j][i] = x;
    }

    __attribute__((always_inline)) void inc(int i, int j, int x) {
        if((a[i][j] += x) >= MOD) a[i][j] -= MOD;
        if((rev[j][i] += x) >= MOD) rev[j][i] -= MOD;
    }

    __attribute__((always_inline)) void dec(int i, int j, int x) {
        if((a[i][j] -= x) < 0) a[i][j] += MOD;
        if((rev[j][i] -= x) < 0) rev[j][i] += MOD;
    }

    __attribute__((always_inline)) int get(int i, int j) const {
        return a[i][j];
    }

    void operator = (const Matrix& oth) {
        memcpy(a, oth.a, sizeof(a));
        memcpy(rev, oth.rev, sizeof(rev));
    }

    friend Matrix operator * (const Matrix& a, const Matrix& b) {
        Matrix c;
        rep(i, N) rep(j, N) c.set(i, j, matmul_helper::dot(a.a[i], b.rev[j]));
        return c;
    }
};

Matrix id() { //identity, TODO: make constexpr
    Matrix a;
    rep(i, N) a.set(i, i, 1);
    return a;
}

Matrix exp(Matrix a, int b) {
    Matrix ans = id();
    for(; b; b >>= 1) {
        if(b & 1) ans = ans * a;
        a = a * a;
    }
    return ans;
}

namespace Solution {
    int n, m, ch[N][26], cnt[N];
    int hsh[N][N], f[N][2];
    queue<int> q;
    Matrix dp;

    int get(int x, int y) {
        static int t=0;
        if(x>y) swap(x, y);
        if(!hsh[x][y]) hsh[x][y]=++t, f[t][0]=x, f[t][1]=y, q.push(t);
        return hsh[x][y];
    }

    void getEdge() {
        get(1, 1);
        while(!q.empty()) {
            int u=q.front(), s1=f[u][0], s2=f[u][1];
            q.pop();
            rep(i, 26) if(ch[s1][i]&&ch[s2][i]) {
                dp.inc(u, get(ch[s1][i], ch[s2][i]), 1);
                dp.inc(u, get(ch[s1][i], 1), cnt[ch[s2][i]]);
                dp.inc(u, get(1, ch[s2][i]), cnt[ch[s1][i]]);
                dp.inc(u, get(1, 1), cnt[ch[s1][i]]*cnt[ch[s2][i]]);
            }
        }
    }

    void solve() {
        cin>>n>>m;
        int t=1;
        rep1(i, n) {
            string s; cin>>s;
            int len=s.size();
            s="#"+s; int ptr=1;
            rep1(j, len) {
                if(!ch[ptr][s[j]-'a']) ch[ptr][s[j]-'a']=++t;
                assert(t<N);
                ptr=ch[ptr][s[j]-'a'];
            }
            cnt[ptr]++;
        }
        getEdge();
        dp=exp(dp, m);
        cout<<dp.get(1, 1)<<endl;
    }
};

int32_t main() {
    fastio;
    Solution::solve();
}