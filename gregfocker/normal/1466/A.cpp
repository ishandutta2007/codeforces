#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        s.insert(v[j] - v[i]);
      }
    }
    cout << (int) s.size() << "\n";
  }
}