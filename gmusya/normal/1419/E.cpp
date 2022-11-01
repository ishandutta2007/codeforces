#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int copy_n = n;
    vector <pair <int, int>> x;
    for (int i = 2; i * i <= n; i++) {
      int cnt = 0;
      while (n % i == 0) {
        cnt++;
        n /= i;
      }
      if (cnt)
        x.push_back({cnt, i});
    }
    if (n > 1)
      x.push_back({1, n});
    sort(x.rbegin(), x.rend());
    if (x[0].first > 1) {
      int m = 1;
      for (int i = 1; i < x.size(); i++)
        while (x[i].first--)
          m *= x[i].second;
      vector <int> p(x[0].first + 1);
      p[0] = 1;
      for (int i = 1; i <= x[0].first; i++)
        p[i] = p[i - 1] * x[0].second;
      vector <int> d;
      for (int j = 2; j * j <= m; j++)
        if (m % j == 0) {
          d.push_back(j);
          if (j * j != m) d.push_back(m / j);
        }
      if (m > 1) d.push_back(m);
      for (auto &now : d) {
        cout << now * p[1] << ' ';
        cout << now * p[0] << ' ';
        for (int i = 2; i < p.size(); i++)
          cout << now * p[i] << ' ';
      }
      for (int i = 1; i < p.size(); i++)
        cout << p[i] << ' ';
      cout << "\n0\n";
      continue;
    }
    if (x.size() == 1) {
      cout << x[0].second << '\n';
      cout << "0\n";
      continue;
    }
    for (int i = 1; i < (1 << x.size()); i++) {
      int mask = (i ^ (i >> 1));
      int tmp = 1;
      for (int j = 0; j < x.size(); j++)
        if ((1 << j) & mask)
          tmp *= x[j].second;
      if (tmp != copy_n) cout << tmp << ' ';
    }
    cout << copy_n << ' ';
    if (x.size() > 2) cout << "\n0\n";
    else cout << "\n1\n";
  }
  return 0;
}