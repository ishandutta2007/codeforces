#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int N; cin >> N;
  int p = 0;
  map<int, int> mp;
  mp[p] = 0;
  int res = 0;
  for (int i = 1; i <= N; i++) {
    int r; cin >> r;
    p += r - 100;
    auto it = mp.lower_bound(p);
    if (it == mp.begin()) mp.emplace(p, i);
    else {
     it--;
     res = max(res, i - it->second);
    }
  }
  cout << res << '\n';
}