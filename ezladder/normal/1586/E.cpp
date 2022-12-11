#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

struct Node {
  int p, r, f;
};

struct DSU {
  static const int SZ = 300007;
  Node t[SZ];

  DSU() { reset(SZ); }

  void reset(int n) {
    for (int i = 0; i < n; ++i) {
      t[i].p = i;
      t[i].r = 0;
      t[i].f = 1;
    }
  }

  int get(int v) {
    if (t[v].p == v) return v;
    return t[v].p = get(t[v].p);
  }

  int get_func(int v) {
    return t[get(v)].f;
  }

  void merge(int a, int b) {
    a = get(a), b = get(b);
    if (a != b) {
      if (t[a].r < t[b].r) swap(a, b);
      t[b].p = a;
      t[a].f += t[b].f;
      if (t[a].r == t[b].r) ++t[a].r;
    }
  }
} dsu;


int n, m;
int col[300007];
vector< pair<int, int> > g[300007];

vector<int> st;
vector<int> ed;
bool dfs(int v, int need, int p = -1) {
  st.pb(v);
  if (v == need) return 1;
  for (auto [to, num] : g[v]) if (to != p) {
    ed.pb(num);
    if (dfs(to, need, v)) return 1;
    ed.pop_back();
  }
  st.pop_back();
  return 0;
}

int RES = 0;
int kok(int v, int p = -1) {
  int now = 0;
  for (auto [to, num] : g[v]) if (to != p) {
    if (kok(to, v)) {
      if (col[num] == 0) ++RES;
      else ++now;
    } else if (col[num]) ++now;
  }

  RES += now / 2;
  now %= 2;

  return now;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    if (dsu.get(w1) != dsu.get(w2)) {
      dsu.merge(w1, w2);
      g[w1].pb(mp(w2, i));
      g[w2].pb(mp(w1, i));
   //   per(w1, w2);
    }
  }

  vector<vector<int> > g;

  int q;
  cin >> q;
  while (q--) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;

    st.clear();
    ed.clear();
    dfs(w1, w2);

    for (int x : ed) col[x] ^= 1;

  //  pper(ed);
  //  pper(st);

    g.pb(st);
  }


  RES += kok(0);

  if (RES == 0) cout << "YES\n"; else cout << "NO\n";

  if (RES == 0)
  for (auto& st : g) {
    cout << st.size() << "\n";
    for (int x : st) cout << x + 1 << ' ';
    cout << "\n";
  }
  else cout << RES;
}