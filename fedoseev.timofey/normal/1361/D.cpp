#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
int gcd(int a, int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
 
pair <int, int> normalize(pair <int, int> p) {
  if (p.first == 0) {
    if (p.second > 0) p.second = 1;
    else if (p.second < 0) p.second = -1;
  } else if (p.second == 0) {
    if (p.first > 0) p.first = 1;
    else if (p.first < 0) p.first = -1;
  } else {
    int g = gcd(abs(p.first), abs(p.second));
    p.first /= g;
    p.second /= g;
  }
  return p;
}
 
ll dist(int x, int y) {
  return (ll)x * x + (ll)y * y;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  map <pair <int, int>, vector <int>> gs;
  vector <int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    gs[normalize({x[i], y[i]})].push_back(i);
  }
  vector <vector <int>> who;
  for (auto p : gs) {
    vector <int> id = p.second;
    sort(id.begin(), id.end(), [&] (int i, int j) {
      return dist(x[i], y[i]) > dist(x[j], y[j]);
    });
    who.push_back(id);
  }  
  vector <double> ds(n);
  for (int i = 0; i < n; ++i) {
    ds[i] = sqrt(dist(x[i], y[i]));
  }
  int m = who.size();
  vector <double> have;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (int)who[i].size(); ++j) {
      int id = who[i][j];
      have.push_back((k - 1) * ds[id] - 2 * j * ds[id]);
    }
  }
  sort(have.rbegin(), have.rend());
  double ans = 0;
  for (int i = 0; i < k; ++i) ans += have[i];
  have.clear();
  for (int i = 0; i < m; ++i) {
    if (2 * (int)who[i].size() > n) {
      int other = n - (int)who[i].size();
      int need = max(0, k - other - (k / 2));
      for (int j = 0; j < k / 2; ++j) {
        int id = who[i][j];
        have.push_back((k - 1) * ds[id] - 2 * j * ds[id]);
      }
      for (int j = 0; j < need; ++j) {
        int id = who[i][(int)who[i].size() - j - 1];
        have.push_back((k - 1) * ds[id] - 2 * (k / 2 + need - j - 1) * ds[id]);
      }
    } else {
      for (int j = 0; j < (int)who[i].size(); ++j) {
        int id = who[i][j];
        have.push_back((k - 1) * ds[id] - 2 * j * ds[id]);
      }
 
    }
  }
  sort(have.rbegin(), have.rend());
  if (have.size() >= k) {
    double nans = 0;
    for (int i = 0; i < k; ++i) nans += have[i];
    ans = max(ans, nans);
  }
  cout << fixed << setprecision(20) << ans << '\n';
}