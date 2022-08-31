#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {

  int n;
  vector<pair<int, int>> res(1);
  cin >> n >> res[0].first >> res[0].second;

  auto ins = [&](int x) {
    cout << "+ " << x << endl;
    int rtrip, rstra;
    cin >> rtrip >> rstra;
    return make_pair(rtrip, rstra);
  };

  map<int, int> mp;
  for (int i = 1; i <= n * 2; ++i) mp[i * (i - 1) / 2] = i;

  for (int i = n; i > 3; --i) res.push_back(ins(i - 1));
  res.push_back(ins(1));
  res.push_back(ins(2));
  res.push_back(ins(1));

  for (int i = n; i; --i) {
    res[i].first -= res[i - 1].first;
    res[i].second -= res[i - 1].second;
  }

  vector<int> ans(n + 1);
  ans[1] = mp[res[n].first] - 1;
  if (res[n - 2].second)
    ans[2] = mp[res[n - 1].first];
  ans[3] = res[n].second / (ans[2] + 1) - 1;
  ans[4] = res[n - 1].second / (ans[3] + 1) - (ans[1] + 1) - 1;
  for (int i = 4; i < n; ++i)
    ans[i + 1] = (res[n - i + 1].second - ans[i - 2] * ans[i - 3]) / (ans[i] + 1) - ans[i - 2] - 1;
  ++ans[n];

  ans.erase(ans.begin(), ans.begin() + 1);
  cout << "! " << ans << endl;

  return 0;
}