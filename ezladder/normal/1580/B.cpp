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

int mod = 0;

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

int dp[107][107][107];

int cnk[444][444];

int fac[444];

int was[107][107][107];

int solve(int n, int m, int k) {
 // per(n, m, k);

  if (was[n][m][k] != -1) return was[n][m][k];

  if (n == 0) {
    return k == 0;
  }

  if (m == 1) {
    if (k == 1) return fac[n];
    return 0;
  }

  int res = 0;

  for (int le = 0; le < n; ++le) {
    int ri = n - le - 1; 
    for (int c1 = 0; c1 <= k; ++c1) {
      int c2 = k - c1;

      int f1 = solve(le, m - 1, c1);
      int f2 = solve(ri, m - 1, c2);

    //  per(n, le, ri, c1, c2, f1, f2);

      add(res, mult(cnk[n - 1][le], mult(f1, f2)));
    }
  }
  return was[n][m][k] = res;
} 


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  int n, m, k;
  cin >> n >> m >> k >> mod;


  for (int i = 0; i < 444; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {;
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  fac[0] = 1;
  for (int i = 1; i < 444; ++i) fac[i] = mult(fac[i - 1], i);

  fill((int*)dp, (int*)dp + 107*107*107, 0);
 // fill((int*)was, (int*)was + 107*107*107, -1);

 // pper(solve(n, m, k)); exit(0);

  for (int len = 1; len <= n; ++len) for (int cnt = 0; cnt <= len; ++cnt) {
    dp[len][1][cnt] = (ll)(cnt == 1) * fac[len];
  }

  for (int lvl = 1; lvl <= m; ++lvl) dp[0][lvl][0] = 1;

 // for (int lvl = 2; lvl <= m; ++lvl) dp[1][lvl][0] = 1;
 // dp[1][1][1] = 1;

  for (int tot_len = 0; tot_len <= n; ++tot_len) {

    for (int need_cnt = 1; need_cnt <= m; ++need_cnt){

      for (int len1 = 0; len1 <= tot_len; ++len1) {
      int len2 = tot_len - len1;

      for (int cnt1 = 0; cnt1 <= len1; ++cnt1) if (dp[len1][need_cnt][cnt1]) {
          for (int cnt2 = 0; cnt2 <= len2; ++cnt2) if (dp[len2][need_cnt][cnt2]) {
          //  if (len1 + len2 + 1 == 4 && need_cnt + 1 == 3 && cnt1 + cnt2 == 2) {
          //    per(len1, cnt1, len2, cnt2);
          //  }
            add(dp[len1 + len2 + 1][need_cnt + 1][cnt1 + cnt2], 
              mult(mult(dp[len1][need_cnt][cnt1], dp[len2][need_cnt][cnt2]),
                cnk[len1 + len2][len1]));
            // cout << dp[len1 + len2 + 1][need_cnt + 1][cnt1 + cnt2] << endl;
          }
        }


      }

    }

  }

 // pper(dp[3][3][1]);
 // pper(dp[0][3][0]);

 // pper(dp[4][4][1]);

  cout << dp[n][m][k];
}