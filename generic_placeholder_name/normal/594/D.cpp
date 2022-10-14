#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

constexpr int logn = 20;
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

constexpr int N=2e5+1;
constexpr int BLOCKSIZE=450;
struct query {
    int l, r, idx; ll ord;
    query() {}
    query(int _l, int _r, int idx): l(_l), r(_r), idx(idx) {ord=order(_l, _r);}
    inline bool operator < (const query& oth) const {
        return ord<oth.ord;
    }
} Q[N];

constexpr int M=1e6+1;
constexpr int MOD=1e9+7;

int gcd_ext(int a, int b, int& x, int& y) {
	if(!a) {
		x=0; y=1;
		return b;
	}
	int x1, y1;
	int d=gcd_ext(b%a, a, x1, y1);
	x=y1-(b/a)*x1; y=x1;
	return d;
}

int inv(int a, int m=MOD) {
    int x, y;
    int g=gcd_ext(a, m, x, y);
    return (x%m+m)%m;
}

int f[M];
int cnt[M];
int v[M];
int a[N];
vi d[N];
int ans[N];
int res=1;
int n, q;

void init() {
    for(int i=2; i<M; i++) if(!f[i]) {
        for(int j=i*2; j<M; j+=i) if(!f[j]) f[j]=i;
    }
    rep(i, M) if(!f[i]) f[i]=i;
    rep(i, n) {
        int x=a[i];
        while(x>1) {
            if(d[i].empty()||f[x]!=d[i].back()) d[i].pb(f[x]);
            x/=f[x];
        }
    }
    rep1(i, M-1) v[i]=inv(i);
}

void add(int i) {
    res=(res*1LL*a[i])%MOD;
    for(int x: d[i]) {
        if(!cnt[x]) res=((res*1LL*(x-1))%MOD)*1LL*v[x]%MOD;
        cnt[x]++;
    }
}

void sub(int i) {
    res=(res*1LL*v[a[i]])%MOD;
    for(int x: d[i]) {
        cnt[x]--;
        if(!cnt[x]) res=((res*1LL*v[x-1])%MOD)*1LL*x%MOD;
    }
}

int32_t main() {
    read(n); rep(i, n) read(a[i]);
    init();
    read(q);
    rep(i, q) {
        int l, r; read(l); read(r); Q[i]=query(l-1, r-1, i);
    }
    sort(Q, Q+q);
    int l=0, r=-1;
    rep(i, q) {
        while(l>Q[i].l) add(--l);
        while(r<Q[i].r) add(++r);
        while(l<Q[i].l) sub(l++);
        while(r>Q[i].r) sub(r--);
        ans[Q[i].idx]=res;
    }
    rep(i, q) writeln(ans[i]);
    putChar(-1);
}