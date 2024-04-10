#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

const int N = 5007;

bool pr[N];
vector <pair <int, int>> p[N];
vector <pair <int, int>> fac[N];

int have[N];

deque <pair <int, int>> rm[N];

int all[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif  
  for (int i = 2; i < N; ++i) pr[i] = true;
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = i; j < N; j += i) {
        if (j > i) pr[j] = false;
        int cnt = 0;
        int cj = j;
        while (cj % i == 0) {
          ++cnt;
          cj /= i;
        }
        p[j].push_back({i, cnt});
      }
    }
  }
  for (int i = 1; i + 1 < N; ++i) {
    vector <pair <int, int>> nw = p[i + 1];
    for (auto pr : fac[i]) {
      nw.push_back(pr);
    }
    sort(nw.begin(), nw.end());
    vector <pair <int, int>> f;
    for (auto pr : nw) {
      if (f.empty() || pr.first != f.back().first) f.push_back(pr);
      else f.back().second += pr.second;
    }
    fac[i + 1] = f;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) x = 1;
    ++have[x];
  }
  ll dist = 0;
  for (int i = 1; i < N; ++i) {
    for (auto pr : fac[i]) {
      dist += (ll)have[i] * pr.second;
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int j = (int)fac[i].size() - 1; j >= 0; --j) {
      rm[i].push_back(fac[i][j]);
    }
  }
  vector <int> alive;
  for (int i = 1; i < N; ++i) if (have[i] > 0 && !rm[i].empty()) alive.push_back(i);
  while (true) {
    for (int i = 1; i < N; ++i) all[i] = 0;
    for (int i : alive) {
      if (rm[i].empty()) continue;
      int cur_cnt = have[i];
      all[rm[i].front().first] += cur_cnt;
    } 
    int bp = -1, best = -1;
    for (int i = 1; i < N; ++i) {
      if (all[i] > best) {
        best = all[i];
        bp = i;
      }
    }
    if (best > n - best) {
      dist -= best - (n - best);
      vector <int> nalive;
      for (int i : alive) {
        if (!rm[i].empty() && rm[i].front().first == bp) {
          --rm[i].front().second;
          if (rm[i].front().second == 0) rm[i].pop_front();
          if (!rm[i].empty()) nalive.push_back(i);
        }
      }
      alive = nalive;
    } else {
      break;
    }
  }
  cout << dist << '\n';
}