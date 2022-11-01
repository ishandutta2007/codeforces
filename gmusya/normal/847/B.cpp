#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vvi ans;
  for (int x : a) {
    int k = ans.size();
    int L = 0, R = k;
    while (L != R) {
      int M = (L + R) / 2;
      if (ans[M].back() > x)
        L = M + 1;
      else
        R = M;
    }
    if (k == L)
      ans.push_back({x});
    else
      ans[L].push_back(x);
  }
  for (auto &now : ans) {
    for (auto &nownow : now)
      cout << nownow << ' ';
    cout << '\n';
  }
  return 0;
}