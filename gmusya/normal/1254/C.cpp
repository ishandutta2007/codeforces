#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long ll;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> p(n);
  iota(p.begin(), p.end(), 1);
  for (int i = n - 1; i >= 2; i--) {
    cout << 2 << ' ' << p[0] << ' ' << p[i - 1] << ' ' << p[i] << endl;
    int res;
    cin >> res;
    if (res < 0)
      swap(p[i], p[i - 1]);
  }
  vector <ll> s(n);
  for (int i = 2; i < n; i++) {
    cout << 1 << ' ' << p[0] << ' ' << p[1] << ' ' << p[i] << endl;
    cin >> s[i];
  }
  int id = 2;
  for (int i = 3; i < n; i++)
    if (s[i] > s[id])
      id = i;
  vector <pair <ll, int>> left;
  vector <pair <ll, int>> right;
  for (int i = 2; i < n; i++) {
    if (i == id)
      continue;
    cout << 2 << ' ' << p[0] << ' ' << p[i] << ' ' << p[id] << endl;
    int res;
    cin >> res;
    if (res < 0)
      left.push_back({s[i], p[i]});
    else
      right.push_back({s[i], p[i]});
  }
  sort(left.rbegin(), left.rend());
  sort(right.begin(), right.end());
  cout << 0 << ' ';
  cout << p[0] << ' ' << p[1] << ' ';
  for (auto &now : right)
    cout << now.second << ' ';
  cout << p[id] << ' ';
  for (auto &now : left)
    cout << now.second << ' ';
  return 0;
}