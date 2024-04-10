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

const int mod = 998244353;

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

int fac[500007];
int ifac[500007];

int cnk(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int n, m;
pair<int, int> a[200007];


const size_t MAX_BIT = 19;
const size_t MAX_SIZE = 1 << MAX_BIT;

/*
 * Fenwick tree on range [0..MAX_SIZE-1]
 *
 *   Range sum    [vl..vr]    - get(vl, vr)
 *   Point update t[v] += val - up(v, val)
 */

struct FenwickTree1 {
  ll t[MAX_SIZE];

  // Sum [0..v]
  ll get(int v) {
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  // Get the leftmost position with a sum >= k
  int getKth(int k) {
    int i = 0;
    for (int bit = MAX_BIT; bit >= 0; bit--) {
      int x = i + (1 << bit) - 1;
      if (x >= MAX_SIZE) {
        continue;
      }
      if (t[x] <= k) {
        i += (1 << bit);
        k -= t[x];
      }
    }
    return i;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
} f;

int pos[200007];

void solve() {
  cin >> n >> m;
  readArr(a, a + m);

  sort(a, a + m, [](pair<int, int> a, pair<int, int> b) {
    return a.x < b.x;
  });

  int mag = m + 1;

  vector<pair<int, int> > t;

  vector<int> cl;

  for (int i = m - 1; i >= 0; --i) {

    int need = a[i].y;

    int vl = 0, vr = 400007;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (vm - f.get(vm) < need) vl = vm; else vr = vm;
    }

    //per(vr, f.get(vr));

    pos[i] = vr;

    f.up(vr, 1);
    cl.pb(vr);

    //pper(need);
//    per(a[i], pos[i]);

    t.pb(mp(pos[i], i));
  }

  for (int x : cl) f.up(x, -1);

  sort(all(t));

//  pper(t);

  for (int i = 0; i + 1 < t.size(); ++i) if (t[i].x == t[i + 1].x - 1 && t[i].y < t[i + 1].y) --mag;

 // pper(mag);
// per(n + 1 + (n - mag) - 1, n - mag);

  cout << cnk(n + 1 + (n - mag) - 1, n - mag) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 500007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 500007; ++i) ifac[i] = bp(fac[i], mod - 2);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}