#include <bits/stdc++.h>
using namespace std;

int n, m;
using ll = long long;

vector<ll> perm(vector<ll> x) {
  ll n = x.size();
  vector<ll> p;
  for (ll i = 2; i <= n; i += 2) p.push_back(x[i - 1]);
  for (ll i = 1; i <= n; i += 2) p.push_back(x[i - 1]);
  return p;
}
  
vector<vector<ll>> find(vector<vector<ll>> v) {
  vector<vector<ll>> r;

  for (ll i = 0; i < n; i++) {
    vector<ll> x, p = perm(v[i]);
    for (ll j = 0; j < m; j++) {
      if (i % 2 == 0) {
        x.push_back(p[j]);
      } else {
        if (m > 4) x.push_back(p[(j + 1) % m]);
        else x.push_back(p[m - 1 - j]);
      }
    }
    r.push_back(x);
  }
  return r;
}

vector<vector<ll>> transpose(vector<vector<ll>> v) {
  vector<vector<ll>> nv(m, vector<ll>(n));

  for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) nv[j][i] = v[i][j];

  return nv;
}

int main() {
  cin >> n >> m;

  vector<vector<ll>> v(n, vector<ll>(m));
  for (ll i = 0; i < n; i++) iota(v[i].begin(), v[i].end(), m * i + 1);
  
  bool swp = false;
  if (n > m) {
    swp = true;
    v = transpose(v);
    swap(n, m);
  }
  
  if (m == 1) {
    cout << "YES\n1\n";
    return 0;
  }

  if (n <= 2 && m <= 3) {
    cout << "NO\n";
    return 0;
  }

  if (n == 3 && m == 3) {
    cout << "YES\n6 7 2\n1 5 9\n8 3 4\n";
    return 0;
  }
  
  v = find(v);
  
  if (swp) {
    v = transpose(v);
    swap(n, m);
  }

  cout << "YES\n";
  for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) cout << v[i][j] << " \n"[j == m - 1];
}