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

const ll INF = 2e18;

int n;
ll a[1000007];
ll res = 0;

int CCC[66];
int FFF[66];

vector<pair<int, char>> d[1000007];

void solve(int vl, int vr) {
  if (vl == vr) {
    ++res;
    return;
  }
  if (vl > vr) return;

  int vm = (vl + vr) >> 1;

  int uk = vm, uk1 = vm, uk2 = vm;
  ll mi = INF, ma = -INF;
  for (int i = vm + 1; i <= vr; ++i) {
    uin(mi, a[i]);
    uax(ma, a[i]);
    while (uk >= vl && a[uk] < ma && a[uk] > mi) {
      --uk;
    }

    int b_mi = __builtin_popcountll(mi);
    int b_ma = __builtin_popcountll(ma);
    if (b_mi == b_ma )
    res += vm - uk;
/*
    while (uk1 >= vl && a[uk1] < ma) {
      --uk1;
    }

    while (uk2 >= vl && a[uk2] > mi) {
      --uk2;
    }

    // 1 mi
    int b_mi = __builtin_popcountll(mi);
    // (uk2..uk1]
    if (uk2 < uk1) {
      d[uk2 + 1].pb(mp(b_mi, 1));
      d[uk1 + 1].pb(mp(b_mi, -1));
    }

    // 1 ma
    int b_ma = __builtin_popcountll(ma);
    if (uk1 < uk2) {
      d[uk1 + 1].pb(mp(b_ma, 2));
      d[uk2 + 1].pb(mp(b_ma, -2));
    } */
  }

/*
  mi = INF, ma = -INF;
  for (int i = vm; i >= vl; --i) {
    uin(mi, a[i]);
    uax(ma, a[i]);
    int b_mi = __builtin_popcountll(mi);
    int b_ma = __builtin_popcountll(ma);
    for (auto [w1, w2] : d[i]) {
      if (w2 == 1) if (b_ma == w1) ++res;
      if (w2 == -1) if (b_ma == w1) --res;
      if (w2 == 2) if (b_mi == w1) ++res;
      if (w2 == -2) if (b_mi == w1) --res;
    }
  }

  for (int i = vl; i <= vr; ++i) d[i].clear(); */

    //////////////////////////////////////////////////////////

  mi = INF, ma = -INF;
  uk = uk1 = uk2 = vm + 1;
  for (int i = vm; i >= vl; --i) {
    // 2
    uin(mi, a[i]);
    uax(ma, a[i]);
    while (uk <= vr && a[uk] <= ma && a[uk] >= mi) {
      ++uk;
    }

    int b_mi = __builtin_popcountll(mi);
    int b_ma = __builtin_popcountll(ma);

    if (b_mi == b_ma)
    res += uk - (vm + 1);
    
    while (uk1 <= vr && a[uk1] <= ma) {
      ++uk1;
    }

    while (uk2 <= vr && a[uk2] >= mi) {
      ++uk2;
    }

    // 1 mi
    // [uk1..uk2)
    if (uk1 < uk2) {
      d[uk2 - 1].pb(mp(b_mi, 1));
      d[uk1 - 1].pb(mp(b_mi, -1));
    //  per(uk1 - 1, uk2 - 1, "find ma");
    }

    // 1 ma
    // [uk2..uk1)
    if (uk2 < uk1) {
      d[uk1 - 1].pb(mp(b_ma, 2));
      d[uk2 - 1].pb(mp(b_ma, -2));
  //    per(uk2 - 1, uk1 - 1, "find mi");

    }

  }

  fill(CCC, CCC + 63, 0);
  fill(FFF, FFF + 63, 0);

  mi = INF, ma = -INF;
  for (int i = vm + 1; i <= vr; ++i) {
    uin(mi, a[i]);
    uax(ma, a[i]);
    int b_mi = __builtin_popcountll(mi);
    int b_ma = __builtin_popcountll(ma);
    CCC[b_mi]++;
    FFF[b_ma]++;
    for (auto [w1, w2] : d[i]) {
      if (w2 == 1) res += FFF[w1];
      if (w2 == -1) res -= FFF[w1];
      if (w2 == 2) res += CCC[w1];
      if (w2 == -2)  res -= CCC[w1];
    }
  }

  for (int i = vl; i <= vr; ++i) d[i].clear();


  solve(vl, vm);
  solve(vm + 1, vr);
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  solve(0, n - 1);

  cout << res;
}