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
pair<ll, ll> a[6666];
// bitset<6001> b[6001];

ull b[6001][94];

ull mask[66];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  for (int i = 0; i < 64; ++i) {
    for (int j = i; j < 64; ++j) mask[i] ^= (ull)1 << j;
  }


  cin >> n;
  readArr(a, a + n);


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
   //   ll now = (a[i].x * a[j].y - a[i].y * a[j].x) / 2;
   //   now %= 2;
   //   if (now < 0) now += 2;

      ll now = 0;

      ll dx = abs(a[i].x - a[j].x) >> 1;
      ll dy = abs(a[i].y - a[j].y) >> 1;

      // pper(((dx & 1) || (dy & 1)));

      if (((dx & 1) || (dy & 1))) b[i][j / 64] ^= (ull)1 << (j % 64);

     // b[i][j] = ; 

     // now += (__gcd(dx, dy) / 2) % 2;
      // now %= 2;

     // b[i][j] = now;
    }
  }

 // cout << ((b[0][0] >> 1) & 1) << endl;

/*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (((b[i][j / 64]) >> j) & 1);
    }
    cout << endl;
  }  */


  ll ans = 0;

  for (int i = 0; i < n; ++i) for (int j = i + 1; j + 1 < n; ++j) {

    int v = j + 1;
    int pos = v / 64;
    int now = 0;


    now += __builtin_popcountll((b[i][pos] ^ b[j][pos]) & mask[v % 64]);

    for (int s = pos + 1; s < 94; ++s) {
      now += __builtin_popcountll(b[i][s] ^ b[j][s]);
    }


   // for (int s = j + 1; s < n; ++s) now += ((b[i][s / 64] >> (s % 64)) & 1) ^ ((b[j][s / 64] >> (s % 64)) & 1);



  //  auto now = (b[i] ^ b[j]).count();

  //  now -= b[i][i] ^ b[j][i];
  //  now -= b[i][j] ^ b[j][j];

  //  per(i, j, now);

    if (((b[i][j / 64] >> (j % 64)) & 1) == 0) {
      ans += n - j - 1 - now;
    } else {
      ans += now;
    } 

  }

  cout << ans;

  exit(0);

  for (int w1 = 0; w1 < n; ++w1)
  for (int w2 = w1 + 1; w2 < n; ++w2)
  for (int w3 = w2 + 1; w3 < n; ++w3)
    if ((b[w1][w2] + b[w2][w3] + b[w3][w1]) % 2 == 0) if (max(b[w1][w2], max(b[w2][w3], b[w1][w3])) == 0) {
      per(a[w1], a[w2], a[w3]);
      per(a[w1].x - a[w2].x, a[w1].y - a[w2].y, a[w3].x - a[w2].x, a[w3].y - a[w2].y);
    }  // ++ans, per(b[w1][w2], b[w2][w3], b[w1][w3]);

  pper(ans);

}