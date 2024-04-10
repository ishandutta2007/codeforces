#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

char getChar() {
    static char buf[1 << 20];
    static int pos = 0;
    static int size = 0;
    if (pos == size) {
        size = fread(buf, 1, 1 << 20, stdin);
        pos = 0;
    }
    if (pos == size) {
        return EOF;
    }
    return buf[pos++];
}


template<typename T>
inline void read(T& v) {
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9'))) c = getChar();
    bool positive = true;
    if (c == '-') {
        positive = false;
        c = getChar();
    }
    v = 0;
    while ('0' <= c && c <= '9') {
        (v *= 10) += (c - '0');
        c = getChar();
    }
    if (!positive) v = -v;
}

void putChar(char c) {
    static char buf[1 << 20];
    static int size = 0;
    if (size == 1 << 20 || c == -1) {
        fwrite(buf, 1, size, stdout);
        size = 0;
    }
    if (c != -1) {
        buf[size++] = c;
    }
}

inline void writeln(int v) {
    char buf[15];
    sprintf(buf, "%d\n", v);
    for (char* cur = buf; *cur != '\0'; ++cur) {
        putChar(*cur);
    }
}

//another sorting order optimization
//testing if actually faster

constexpr int logn = 19;
constexpr int maxn = 1 << logn;

long long order(int x, int y)
{
	long long d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | rx * 3 ^ static_cast<int>(ry);
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}

constexpr int N=5e5+1;
constexpr int BLOCKSIZE=800;
struct query {
    int l, r, idx; ll ord;
    query() {}
    query(int _l, int _r, int idx): l(_l), r(_r), idx(idx) {ord=order(_l, _r);}
    bool operator < (const query& oth) const {
        return ord<oth.ord;
    }
};

int a[N], ans[N], cnt[N+1];
vi v;
bitset<N+1> inv;

inline void upd(int i) {
    if(cnt[a[i]]==1&&!inv[a[i]]) {
        v.pb(a[i]);
        inv[a[i]]=1;
    }
}

inline void add(int i) {
    cnt[a[i]]++;
    upd(i);
}

inline void sub(int i) {
    cnt[a[i]]--;
    upd(i);
}

int32_t main() {
    int n, q;
    read(n); rep(i, n) read(a[i]);
    read(q); query Q[q];
    rep(i, q) {int l, r; read(l), read(r); Q[i]=query(l-1, r-1, i);}
    int ans[q];
    sort(Q, Q+q);
    v.reserve(N);
    int l=0, r=-1;
    rep(i, q) {
        while(l<Q[i].l) sub(l++);
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) sub(r--);
        while(r<Q[i].r) add(++r);
        while(!v.empty()&&cnt[v.back()]!=1) inv[v.back()]=0, v.pop_back();
        ans[Q[i].idx]=v.empty()?0:v.back();
    }
    rep(i, q) writeln(ans[i]);
    putChar(-1);
}