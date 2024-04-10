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


const size_t MAX_SIZE = 1 << 18;

/*
 * Fenwick tree on range [0..MAX_SIZE-1]
 *
 *   Range sum    [vl..vr]    - get(vl, vr)
 *   Point update t[v] += val - up(v, val)
 */

struct FenwickTree1 {
  int t[MAX_SIZE];

  // Sum [0..v]
  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      add(res, t[v]);
    }
    return res;
  }

  // Sum [vl..vr]
  int get(int vl, int vr) {

    if (vl > vr) return 0;

    int res = get(vr);
    if (vl > 0) {
      dec(res,get(vl - 1));
    }
    return res;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      add(t[v], val);
    }
  }
} f;

int n;
int x[200007];
int y[200007];
int s[200007];
int dp[200007];


int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> s[i];

  x[n] = x[n - 1] + 1;

  int res = x[0] % mod;

  
  for (int i = 0; i < n; ++i) {

    int vl = -1, vr = i;
    while (vl + 1 < vr){
      int vm = (vl + vr) >> 1;
      if (x[vm] > y[i]) vr = vm; else vl = vm;
    }


    add(dp[i], (x[vr] - y[i]) % mod);

    add(dp[i], f.get(vr, i - 1));

    add(dp[i], (x[i + 1] - x[i]) % mod);



    f.up(i, dp[i]);


  //  per(i);
  //  pper(dp[i]);

    
    if (s[i] == 1) add(res, dp[i]); else {
          add(res, (x[i + 1] - x[i]) % mod);

    }

  }


  cout << res;

}