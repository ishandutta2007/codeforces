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
pair<pair<int, int>, int> a[100007];
pair<pair<int, int>, int> b[100007];
pair<pair<int, int>, int> c[100007];
pair<pair<int, int>, int> d[100007];

pair<int, int> cnt[100007]; 

bool ok(pair<pair<int, int>, int>* a, int w1, int w2, int w3, int KEK) {
  int need = KEK;
  int last_x = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i].y == w1) {
      --need;
      last_x = a[i].x.x;
      if (need == 0) break;
    }
  }

  auto LAST = last_x;

  if (need > 0) return 0;


  fill(cnt, cnt + n + 1, mp(0, 0));
  for (int i = 0; i < n; ++i) {
    if (a[i].x.x > last_x) {
      if (a[i].y == w2) {
        ++cnt[a[i].x.x].x;
      } else if (a[i].y == w3) {
        ++cnt[a[i].x.x].y;
      }
    }
  } 

  need = KEK;

  for (int i = 0; i <= n; ++i) {
    need -= cnt[i].x;
    if (need <= 0) {
      last_x = i;
      break;
    }
  }
  if (need <= 0) {
    need = KEK;
    for (int i = last_x + 1; i <= n; ++i) {
      need -= cnt[i].y;
    }
    if (need <= 0) return 1;
  }


  last_x = LAST;

  fill(cnt, cnt + n + 1, mp(0, 0));
  for (int i = 0; i < n; ++i) {
    if (a[i].x.x > last_x) {
      if (a[i].y == w2) {
        ++cnt[a[i].x.y].x;
      } else if (a[i].y == w3) {
        ++cnt[a[i].x.y].y;
      }
    }
  } 

  need = KEK;

  for (int i = 0; i <= n; ++i) {
    need -= cnt[i].x;
    if (need <= 0) {
      last_x = i;
      break;
    }
  }
  if (need <= 0) {
    need = KEK;
    for (int i = last_x + 1; i <= n; ++i) {
      need -= cnt[i].y;
    }
    if (need <= 0) return 1;
  }

  return 0;
}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  vector<int> xx, yy;
  for (int i = 0; i < n; ++i) {
    xx.pb(a[i].x.x);
    yy.pb(a[i].x.y);
  }

  sort(all(xx));
  sort(all(yy));
  xx.resize(unique(all(xx)) - xx.begin());
  yy.resize(unique(all(yy)) - yy.begin());

  for (int i = 0; i < n; ++i) {
    a[i].x.x = lower_bound(all(xx), a[i].x.x) - xx.begin();
    a[i].x.y = lower_bound(all(yy), a[i].x.y) - yy.begin();
  }
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
    swap(b[i].x.x, b[i].x.y);
  }

  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
    c[i].x.x = n - c[i].x.x - 1;
    d[i] = b[i];
    d[i].x.x = n - d[i].x.x - 1;
  }

  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
  sort(d, d + n);





  int vl = 0, vr = n / 3 + 1;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;

    if (ok(a, 1, 2, 3, vm) || 
        ok(a, 1, 3, 2, vm) || 
        ok(a, 2, 1, 3, vm) || 
        ok(a, 2, 3, 1, vm) || 
        ok(a, 3, 1, 2, vm) || 
        ok(a, 3, 2, 1, vm) || 

        ok(b, 1, 2, 3, vm) || 
        ok(b, 1, 3, 2, vm) || 
        ok(b, 2, 1, 3, vm) || 
        ok(b, 2, 3, 1, vm) || 
        ok(b, 3, 1, 2, vm) || 
        ok(b, 3, 2, 1, vm) ||

        ok(c, 1, 2, 3, vm) || 
        ok(c, 1, 3, 2, vm) || 
        ok(c, 2, 1, 3, vm) || 
        ok(c, 2, 3, 1, vm) || 
        ok(c, 3, 1, 2, vm) || 
        ok(c, 3, 2, 1, vm) ||

        ok(d, 1, 2, 3, vm) || 
        ok(d, 1, 3, 2, vm) || 
        ok(d, 2, 1, 3, vm) || 
        ok(d, 2, 3, 1, vm) || 
        ok(d, 3, 1, 2, vm) || 
        ok(d, 3, 2, 1, vm)
        )
      vl = vm; else vr = vm;
  }

  cout << vl * 3;
}