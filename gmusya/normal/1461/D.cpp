#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

set <ll> pos;

void hm(vector <int> &a) {
  ll sum = 0;
  for (auto &now : a)
    sum += now;
  pos.insert(sum);
  bool flag = true;
  for (int i = 0; i + 1 < (int)a.size(); i++)
    if (a[i] != a[i + 1])
      flag = false;
  if (flag)
    return;
  int mid = (*min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end())) / 2;
  vector <int> b, c;
  for (auto &now : a) {
    if (now <= mid)
      b.push_back(now);
    else
      c.push_back(now);
  }
  hm(b);
  hm(c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    pos = set<ll>();
    hm(a);
    while (q--) {
      ll s;
      cin >> s;
      if (pos.find(s) == pos.end())
        cout << "No\n";
      else
        cout << "Yes\n";
    }
  }
  return 0;
}