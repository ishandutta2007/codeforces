#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;

  cin >> N;
  map< int, multiset< int > > mp;

  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int sum = 0, small = 0;
    for(auto &c : s) {
      sum += c == '(' ? 1 : -1;
      small = min(small, sum);
    }
    mp[sum].emplace(small);
  }

  int ret = 0;
  for(auto &p : mp) {
    if(p.first < 0) continue;
    if(p.first == 0) {
      auto& ps = p.second;
      int a = 0;
      for(auto& small : ps) {
        if(small == 0) ++a;
      }
      ret += a / 2;
    } else {
      if(!mp.count(-p.first)) continue;
      auto &ps = p.second;
      auto &qs = mp[-p.first];

      for(auto &small : ps) {
        if(small < 0) continue;
        if(qs.empty()) continue;
        auto it = prev(qs.end());
        if(*it == -p.first) {
          qs.erase(it);
          ++ret;
        }
      }
    }
  }

  cout << ret << endl;
}