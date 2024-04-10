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

#define gc (p1 == p2 && (p2 = (p1 = buf) + \
	fread(buf, 1, 1 << 22, stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (*O++ = x)
#define flush() fwrite(obuf, 1, O - obuf, stdout)
char buf[1 << 22], *p1 = buf, *p2 = buf, obuf[1 << 25], *O = obuf;
int read() {
	int x = 0, sgn = 0; char s = gc;
	while(!isdigit(s)) sgn |= s == '-', s = gc;
	while(isdigit(s)) x = (x << 1) + (x << 3) + s - '0', s = gc;
	return sgn ? -x : x;
}
char read_() {
    char s = gc;
    while(s != '*' && s != '/') s = gc;
    return s;
}
void recprint(int x) {if(x > 9) recprint(x / 10); pc(x % 10 + '0');}
void print(int x) {if(x < 0) x = -x, pc('-'); recprint(x);}

struct FastSet {
  int bsr(ull x) { return 63 - __builtin_clzll(x); }
  int bsf(ull x) { return __builtin_ctzll(x); }

  static constexpr uint B = 64;
  int n, lg;
  vector<vector<ull>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vector<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void insert(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void erase(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B])
        break;
      i /= B;
    }
  }

  int next(int i) {
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size())
        break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      // find

      i += bsf(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsf(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }

  int prev(int i) {
    if(i < 0) return -1;
    i = min(i, n - 1);
    for (int h = 0; h < lg; h++) {
      if (i == -1)
        break;
      ull d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      // find

      i += bsr(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsr(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }
};

constexpr int N = 1e6 + 5;
constexpr int P = 8e4 + 5;
int a[N];
int f[N];
int cnt[N];
int p[N];
vector<int> st[P];

int32_t main() {
    fastio;
    for(int i = 2; i * i < N; i++) if(!f[i]) {
        for(int j = i * i; j < N; j += i) if(!f[j]) f[j] = i;
    }
    for(int i = 2, t = 0; i < N; i++) if(!f[i]) {
        f[i] = i;
        p[i] = ++t;
    }
    int n = read();
    rep(i, n) a[i] = read();
    vector<char> t(n); rep(i, n) t[i] = read_();
    FastSet s(n);
    auto dec = [&](int x) {
        cnt[x]--;
        if(!cnt[x]) s.erase(x);
    };
    auto inc = [&](int x) {
        if(!cnt[x]) s.insert(x);
        cnt[x]++;
    };
    ll ans = 0;
    for(int i = n - 1; ~i; i--) {
        if(t[i] == '/') {
            for(int k = a[i]; k != 1; k /= f[k]) {
                int x = p[f[k]];
                bool mpt = st[x].empty();
                bool ps = !st[x].empty() && st[x].back() != i;
                if(ps) dec(st[x].back());
                st[x].pb(i);
                if(mpt || ps) inc(i);
            }
            if(a[i] == 1) ans += s.next(i) - i;
        }
        else {
            if(!(a[i] & 1)) {
                int x = __builtin_ctz(a[i]);
                a[i] >>= x;
                if(!st[1].empty()) {
                    dec(st[1].back());
                    if(st[1].size() <= x) st[1] = {};
                    else {
                        st[1].resize(st[1].size() - x);
                        inc(st[1].back());
                    }
                }
            }
            for(int k = a[i]; k != 1; k /= f[k]) {
                int x = p[f[k]];
                if(st[x].empty()) continue;
                dec(st[x].back());
                st[x].pop_back();
                if(!st[x].empty()) inc(st[x].back());
            }
            ans += s.next(i) - i;
        }
    }
    cout << ans << endl;
}