#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

set<int> s;
const int N = 200000 + 7;

int smart(int n, int a[]) {
  reverse(a + 1LL, a + n + 1LL);
  s.clear();
  { /// first is 0
    for (int pre = 0; pre < n; pre++) {
      ///  from 0...pre = 0
      /// pre + 1LL = 1LL
      /// pre + 2 = 0
      /// pre + 3 = 1LL
      /// pre + 4 = 0
      int zero = (1LL << (pre + 1LL)) - 1LL;
      for (int fin = pre; fin < n; fin += 2) {
        zero |= (1LL << fin);
        s.insert((1LL << n) - 1LL - zero);
        if (fin + 3 < n) {
          s.insert((1LL << n) - 1LL - (zero + (1LL << (n - 1LL))));
        }
      }
    }
  }
  { /// first one is 1LL
    for (int pre = 1LL; pre < n; pre++) {
      /// from 1LL...pre = 0
      /// pre + 1LL = 1LL
      /// pre + 2 = 0
      /// pre + 3 = 1LL
      /// pre + 4 = 0
      int zero = (1LL << (pre + 1LL)) - 1LL - 1LL;
      for (int fin = pre; fin < n; fin += 2) {
        zero |= (1LL << fin);
        s.insert((1LL << n) - 1LL - zero);
        if (fin + 3 < n) {
          s.insert((1LL << n) - 1LL - (zero + (1LL << (n - 1LL))));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      s.insert((1LL << (i + 1LL)) - 1LL);
    }
  }
  int sol = 0;
  for (auto &mask : s) {
    int in = 0, out = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1LL << i)) in += a[i + 1LL];
      else out += a[i + 1LL];
    }
    sol += (in < out);
  }
  reverse(a + 1LL, a + n + 1LL);
  return sol % 998244353;
}

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1LL;
  while (b) {
    if (b & 1LL) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

bool test(int n, int mask) {
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    if (mask & (1LL << i)) a.push_back(i);
    else b.push_back(i);
  }
  bool ok = 1LL;
  for (int i = 1LL; i + 1LL < (int) a.size(); i++) {
    ok &= (a[i] - a[i - 1LL] <= a[i + 1LL] - a[i]);
  }
  swap(a, b);
  for (int i = 1LL; i + 1LL < (int) a.size(); i++) {
    ok &= (a[i] - a[i - 1LL] >= a[i + 1LL] - a[i]);
  }
  swap(a, b);
  return ok;
}

void print(int n, int mask) {
  for (int i = n - 1LL; i >= 0; i--) {
    if (mask & (1LL << i)) cout << 1LL;
    else cout << 0;
  }
  cout << "\n";
}

int rev(int n, int mask) {
  int sol = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1LL << i)) {
      sol += (1LL << (n - 1LL - i));
    }
  }
  return sol;
}


void put(int n) {
  s.clear();
  { /// first is 0
    for (int pre = 0; pre < n; pre++) {
      ///  from 0...pre = 0
      /// pre + 1LL = 1LL
      /// pre + 2 = 0
      /// pre + 3 = 1LL
      /// pre + 4 = 0
      int zero = (1LL << (pre + 1LL)) - 1LL;
      for (int fin = pre; fin < n; fin += 2) {
        zero |= (1LL << fin);
        s.insert(rev(n, (1LL << n) - 1LL - zero));
        if (fin + 3 < n) {
          s.insert(rev(n, (1LL << n) - 1LL - (zero + (1LL << (n - 1LL)))));
        }
      }
    }
  }
  { /// first one is 1LL
    for (int pre = 1LL; pre < n; pre++) {
      /// from 1LL...pre = 0
      /// pre + 1LL = 1LL
      /// pre + 2 = 0
      /// pre + 3 = 1LL
      /// pre + 4 = 0
      int zero = (1LL << (pre + 1LL)) - 1LL - 1LL;
      for (int fin = pre; fin < n; fin += 2) {
        zero |= (1LL << fin);
        s.insert(rev(n, (1LL << n) - 1LL - zero));
        if (fin + 3 < n) {
          s.insert(rev(n, (1LL << n) - 1LL - (zero + (1LL << (n - 1LL)))));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      s.insert(rev(n, (1LL << (i + 1LL)) - 1LL));
    }
  }
  for (int i = 0; i < n; i++) {
   // s.insert((1LL << i));
    //s.insert((1LL << n) - 1LL - (1LL << i));
  }
}


int n;
int a[N], pre[2][N], total[N];

int getsumx(int mod, int l, int r) {
  if (l > r) return 0;
  return pre[mod][r] - pre[mod][l - 1];
}

int get(int pre, int fin) {
  int in = 0;
  in = getsumx((pre + 2) % 2, pre + 2, fin + 1);
  if (fin + 2 <= n) {
    in += total[n] - total[fin + 1];
  }
  return in;
}

int megasmart(int nn, int vec[]) {
  n = nn;
  int sol = 0;
  int lim = 0;
  for (int i = 0; i < n; i++) {
    a[i] = vec[i + 1];
    lim += a[i];
  }
  reverse(a, a + n);
  for (int i = 1; i <= n; i++) {
    for (int m = 0; m <= 1; m++) {
      pre[m][i] = pre[m][i - 1];
    }
    pre[i % 2][i] += a[i - 1];
    total[i] = total[i - 1] + a[i - 1];
  }
  lim--;
  lim /= 2;
  for (int it = 0; it < 2; it++) {
    for (int pre = it; pre < n; pre++) {
      int lo = 0, hi = (n - 1 - pre) / 2, first = n + 1;
      while (lo <= hi) {
        int j = (lo + hi) / 2;
        int fin = pre + 2 * j;
        bool ok = 0;
        if (get(pre, fin) <= lim) {
          ok = 1;
        }
        if (ok) {
          first = j;
          hi = j - 1;
        } else {
          lo = j + 1;
        }
      }
      hi = (n - 1 - pre) / 2;
      if (first <= hi) {
        sol += hi - first + 1;
      }
      if (n - 4 - pre >= 0) {
        lo = 0, hi = (n - 4 - pre) / 2;
        first = n + 1;
        while (lo <= hi) {
          int j = (lo + hi) / 2;
          int fin = pre + 2 * j;
          bool ok = 0;
          if (get(pre, fin) - a[n - 1] <= lim) {
            ok = 1;
          }
          if (ok) {
            first = j;
            hi = j - 1;
          } else {
            lo = j + 1;
          }
        }
        hi = (n - 4 - pre) / 2;
        if (first <= hi) {
          sol += hi - first + 1;
        }
      }
    }
    lim -= a[0];
  }
  lim += 2 * a[0];
  {
    int in = a[0];
    for (int i = 1; i < n; i++) {
      in += a[i];
      sol += (in <= lim);
    }
  }

  //exit(0);
  return sol % M;
}



int brute(int n, int a[]) {
  int sol = 0;
  for (int mask = 0; mask < (1LL << n); mask++) {
    if (test(n, mask)) {
     /// cout << "hey : " << n << "\n";
      int in = 0, out = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1LL << i)) in += a[i + 1LL];
        else out += a[i + 1LL];
      }
      sol += (in < out);
    }
  }
  return sol;
}

mt19937 rng(0);

void print() {
  freopen ("input", "w", stdout);
  int t = 1;
  cout << t << "\n";
  for (int i = 1LL; i <= t; i++) {
    int n = rng() %  + 1LL;
    n = 200000;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
      cout << rng() % 10 + 1LL << " ";
    }
    cout << "\n";
  }
  exit(0);
}


int vec[N];

signed main() { /// after finishing task D, DO NOT FORGET TO LOOK BACK AT "DEFINE INT LONG LONG" !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  ios::sync_with_stdio(0); cin.tie(0);
 // print();
 // freopen ("input", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      for (int i = 1LL; i <= n; i++) {
        cin >> vec[i];
      }
     // int x = brute(n, a);
      int x = megasmart(n, vec);
      cout << x << "\n";
    }
    return 0;
/**
  {
    freopen ("input", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      for (int i = 1LL; i <= n; i++) {
        cin >> vec[i];
      }
     // int x = brute(n, a);
      int x = megasmart(n, vec);
      int y = smart(n, vec);

      cout << x << " and " << y << "\n";
      assert(x == y);
    }
    return 0;
  }
**/

/// DO NOT FORGET ABOUT FAST IO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

 /// print();

  for (int n = 1LL; n <= 100; n++) {
    int cnt = 0;
    for (int mask = 0; mask < (1LL << n); mask++) {
      if (test(n, mask)) {
        cnt++;
        if (n == 12) {
         /// print(n, mask);
        }
      //  print(n, mask);
      }
    }
    //cout << "\n";
    put(n);
    assert((int) s.size() == cnt);
    cout << n << " : " << cnt << "\n";
    for (auto &x : s) {
      if (!test(n, x)) {
        cout << "n = " << n << "\n";
        print(n, x);
        cout << "I say it is ok, but it isn't\n";
        return 0;
      }
      assert(test(n, x));
    }
    /// f(n) = (shifted off by 1LL) n * n + n + 2
    //assert(cnt == n * n - n + 2);
   /// cout << cnt << ", ";
  }
  return 0;
}