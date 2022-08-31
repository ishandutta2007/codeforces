#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  map< int, vector< int > > ev;

  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int sum = 0, ret = 0;
    for(auto &c : s) {
      sum += c == '(' ? 1 : -1;
      ret = min(ret, sum);
    }
    ev[sum].emplace_back(ret);
  }

  for(auto &t : ev) {
    sort(begin(t.second), end(t.second));
  }
  int64 ret = 0;
  for(auto &s : ev) {
    if(!ev.count(-s.first)) continue;
    auto &t = ev[-s.first];
    for(auto low : s.second) {
      if(low < 0) continue;
      auto pos = lower_bound(begin(t), end(t), -s.first) - begin(t);
      ret += (int) t.size() - pos;
    }
  }
  cout << ret << endl;
}