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

int n;
int t[111];

int p[15][15];
int q[15][15];

int strong[1 << 14];

int pref[14][1 << 14];

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(t, t + n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
    p[i][j] = mult(t[i], bp((t[i] + t[j]) % mod, mod - 2));
    q[i][j] = 1;
    dec(q[i][j], p[i][j]);
  }

  for (int v = 0; v < n; ++v) for (int mask = 0; mask < (1 << n); ++mask) {
    pref[v][mask] = 1;
    for (int i = 0; i < n; ++i) if ((mask >> i) & 1) pref[v][mask] = mult(pref[v][mask], p[v][i]);
  }

  for (int mask = 1; mask < (1 << n); ++mask) {

    strong[mask] = 1;

    int sub = mask; 

    while (1) {
      sub = (sub - 1) & mask;
      if (sub == 0) break;

      int now = strong[sub];



      for (int i = 0; i < n; ++i) if ((sub >> i) & 1)
        now = mult(now, pref[i][mask ^ sub]);


     // per(mask, sub, now);

      dec(strong[mask], now);

    }

  }

  int res = 0;

  for (int mask = 1; mask < (1 << n); ++mask) {
    int now = __builtin_popcount(mask);
    now = mult(now, strong[mask]);

    for (int i = 0; i < n; ++i) if (!((mask >> i) & 1))
    for (int j = 0; j < n; ++j) if (((mask >> j) & 1))
      now = mult(now, p[j][i]);

   // per(mask, now);

    add(res, now);
  }

  cout << res;
}