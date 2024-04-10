#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
int n;
int a[N];
set<int> s;
set<int> s2;

int bef(int i) {
  assert(s.count(i));
  auto it = s.find(i);
  if (it == s.begin()) {
    it = s.end();
  }
  it--;
  return *it;
}

int nxt(int i) {
  assert(s.count(i));
  auto it = s.find(i);
  it++;
  if (it == s.end()) {
    it = s.begin();
  }
  return *it;
}



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    s.clear();
    s2.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s.insert(i);
    }
    for (int i = 1; i <= n; i++) {
      int j = bef(i);
      if (__gcd(a[j], a[i]) == 1) {
        s2.insert(i);
      }
    }
    vector<int> ret;
    int i = 2;
    while (!s2.empty()) {
      auto it = s2.lower_bound(i);
      if (it == s2.end()) {
        it = s2.begin();
      }
      i = *it;
      assert(s.count(i));
      assert(s2.count(i));
      int j1 = bef(i), j2 = nxt(i);
      s2.erase(j2);
      if (__gcd(a[j1], a[j2]) == 1) {
        s2.insert(j2);
      }
      s.erase(i);
      s2.erase(i);
      ret.push_back(i);
      i = j2 + 1;
    }
    cout << (int) ret.size() << " ";
    for (auto &i : ret) {
      cout << i << " ";
    }
    cout << "\n";
  }

}