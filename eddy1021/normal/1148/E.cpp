#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
typedef long long LL;
LL n, s[N], t[N], sid[N];
void no() {
  puts("NO");
  exit(0);
}
vector<pair<pair<int,int>, int>> ans;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%lld", &s[i]);
  }
  for (int i = 0; i < n; ++ i) {
    scanf("%lld", &t[i]);
  }
  for (int i = 0; i < n; ++ i) {
    sid[i] = i;
  }
  sort(sid, sid + n, [&](int id1, int id2){
    return s[id1] < s[id2];
  });
  sort(t, t + n);
  LL pdlt = 0;
  for (int i = 0; i < n; ++ i) {
    pdlt += t[i] - s[sid[i]];
    if (pdlt < 0) {
      no();
    }
  }
  if (pdlt != 0) {
    no();
  }
  for (int i_ = 0, j_ = 0; i_ < n; ++ i_) {
    int i = sid[i_];
    while (s[i] != t[i_]) {
      while (true) {
        int j = sid[j_];
        if (t[j_] >= s[j]) {
          ++ j_;
          continue;
        }
        break;
      }
      int j = sid[j_];
      int gain = min(t[i_] - s[i], s[j] - t[j_]);
      assert(gain > 0);
      ans.push_back({{i, j}, gain});
      s[i] += gain;
      s[j] -= gain;
    }
  }
  puts("YES");
  printf("%d\n", (int)ans.size());
  for (auto p: ans) {
    printf("%d %d %d\n", p.first.first + 1, p.first.second + 1, p.second);
  }
}