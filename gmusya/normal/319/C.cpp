#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

struct line {
  ll k, b, l;
  line(ll _k, ll _b) {
    k = _k, b = _b, l = 0;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector <line> st;
  vector <ll> dp(n);
  {
    line tmp(b[0], dp[0]);
    st.push_back(tmp);
  }
  for (int i = 1; i < n; i++) {
    {
      int L = 0, R = (int)st.size() - 1;
      while (L != R) {
        int M = (L + R + 1) / 2;
        if (st[M].l > a[i])
          R = M - 1;
        else
          L = M;
      }
      dp[i] = st[L].k * a[i] + st[L].b;
    }
    line ne(b[i], dp[i]);
    while (!st.empty()) {
      line ol = st.back();
      ll x = (ol.b - ne.b + ne.k - ol.k - 1) / (ne.k - ol.k);
      if (x <= ol.l) {
        st.pop_back();
        continue;
      }
      ne.l = x;
      st.push_back(ne);
      break;
    }
  }
  cout << dp[n - 1];
  return 0;
}