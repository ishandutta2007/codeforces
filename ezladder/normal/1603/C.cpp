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

int MA = 100001;

int n;
int a[100007];

struct ST {
  int vl, vr, val;
};

//vector<int> dd[100007];
//vector<int> ff[100007];


int ff[100007];

int GO(int i) {
  int sz = 0;
  int last = 1;
  while (1) {
    ff[sz++] = (last);

    if (last == i) break;

    int k = ((i + last - 1) / last) - 1;

    last = (i + k - 1) / k;
  }
  ff[sz++] = (MA);
  return sz;
}

ST g[2][100007];

void solve() {
  cin >> n;
  readArr(a, a + n);

  int res = 0;

  int KK = 0;
  int cur_sz = 1;
  g[0][0] = ST{1, MA, 0};


  for (int i = 0; i < n; ++i) {

    int sz = GO(a[i]);

    // vector<ST> now((int)ff[a[i]].size() - 1);


    int new_sz = 0;


    int uk = 0;

    for (int j = 0; j + 1 < sz; ++j) {
      int y = ff[j];
      int extra = (a[i] + y - 1) / y;
      int need = a[i] / extra;

      while (g[KK][uk].vr < need) ++uk;

      int val = g[KK][uk].val;

      add(val, mult(extra - 1, i + 1));

      g[KK ^ 1][new_sz++] = ST{ff[j], ff[j + 1] - 1, val};
    }
/*
    for (auto& c : now) {
      cout << c.vl << ' ' << c.vr << ' ' << c.val << endl;
    }

    cout << endl; */

    // swap(g, now);

    add(res, g[KK ^ 1][new_sz - 1].val);
    
    KK ^= 1;
    cur_sz = new_sz;
  }


  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  /*
  for (int i = 1; i <= MA; ++i) {
    int last = 1;
    while (1) {
      dd[i].pb(last);

      if (last == i) break;

      int vl = last, vr = i;
      while (vl + 1 < vr) {
        int vm = (vl + vr) >> 1;
        if ((i + last - 1) / last != (i + vm - 1) / vm) vr = vm; else vl = vm;
      }

      last = vr;
    }
    cout << i << ' ' << dd[i].size() << endl;
  }
*/

/*
  for (int i = 1; i <= MA; ++i) {
    int last = 1;
    while (1) {
      ff[i].pb(last);

   //   per(i, last);

      if (last == i) break;

      int k = ((i + last - 1) / last) - 1;

      last = (i + k - 1) / k;
    }
    ff[i].pb(MA);
    // assert(ff[i] == dd[i]);
    //cout << i << ' ' << ff[i].size() << endl;
  }

  */

  int tt;
  cin >> tt;
  while (tt--) { solve(); }

}