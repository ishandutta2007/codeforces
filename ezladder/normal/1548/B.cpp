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
ll a[200007];
ll b[200007];

ll t1[200007];
ll t2[200007];

int rec(int vl, int vr) {
  if (vl == vr) {
    return 1;
  } else {
    int vm = (vl + vr) >> 1;

    ll save = a[vm];
    for (int i = vl; i <= vr; ++i) {
      b[i] = abs(a[i] - save);
    }

    //for (int i = vl; i <= vr; ++i) cout << b[i] << ' ';
   //   cout << endl;

    ll last = 0;
    for (int i = vm; i >= vl; --i) {
      last = t1[i] = __gcd(last, b[i]); 
    }

    last = 0;
    for (int i = vm + 1; i <= vr; ++i) {
      last = t2[i] = __gcd(last, b[i]); 
    }

    int uk = vl;

    int ans = 0;

    for (int i = vm + 1; i <= vr; ++i) {
      if (t2[i] == 1) break;
      while (uk <= vm && __gcd(t2[i], t1[uk]) == 1) uk++;
    //  per(i, uk, t1[uk], t2[i]);
      if (uk == vm + 1) break;
      uax(ans, i - uk + 1);
    }


    for (int i = vl; i <= vr; ++i) a[i] += save;

 //  per(vl, vr, ans);

 // exit(0);

    return max(ans, max(rec(vl, vm), rec(vm + 1, vr)));
  }
}

void solve() {
  cin >> n;
  readArr(a, a + n);

  cout << rec(0, n - 1) << "\n";

}


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}