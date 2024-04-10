#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[300005], p[300005];
vector<int> left_[300005], right_[300005];
set<int> f;
const int MAX = 22;
const int UP = MAX + 1;

bool cmp(int i, int j) {
  return arr[i] < arr[j] || arr[i] == arr[j] && i < j; 
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    p[i] = i;
  }
  sort(p, p + n, cmp);
  set<int>::iterator it;
  for (int i = n - 1; i >= 0; --i) {
    it = f.upper_bound(p[i]);
    for (int j = 0; it != f.end() && j < UP; ++j) {
      right_[p[i]].push_back(*it);
      ++it;
    }
    it = f.upper_bound(p[i]);
    if (it != f.begin()) { 
      --it;
      for (int j = 0; j < UP; ++j) {
        left_[p[i]].push_back(*it);
        if (it == f.begin()) break;
        --it;
      }
    }
    f.insert(p[i]);
  }
  
  long double pw2[150] = {0}, sums[150] = {0};
  pw2[0] = 1;
  for (int i = 1; i < 140; ++i)
    pw2[i] = pw2[i - 1] * 2;
  long double ans = 0;
  for (int t = 0; t < n; ++t) {
    for (int i = 0; i <= left_[t].size(); ++i) {
      int lp = (i == 0 ? t : left_[t][i - 1]) - (i < left_[t].size() ? left_[t][i] : -1);
      for (int j = 0; j <= right_[t].size() && i + j <= MAX; ++j) {
        int rp = (j < right_[t].size() ? right_[t][j] : n) - (j == 0 ? t : right_[t][j - 1]);
        // cout << t << "  " << lp << "  " << rp << "  " << i + j << endl;
        sums[i + j + 1] += 1.0 * arr[t] * lp * rp;
      }
    }
  }
  for (int i = 0; i <= 100; ++i)
    ans += sums[i] / pw2[i];
  // for (int t = 0; t < n; ++t) {
  //   long double L = 0, R = 0;
  //   for (int i = 0; i <= left_[t].size(); ++i) {
  //     int lp = (i == 0 ? t : left_[t][i - 1]) - (i < left_[t].size() ? left_[t][i] : -1);
  //     L += 1.0 * lp / pw2[i];
  //   }
  //   for (int j = 0; j <= right_[t].size(); ++j) {
  //     int rp = (j < right_[t].size() ? right_[t][j] : n) - (j == 0 ? t : right_[t][j - 1]);
  //     // cout << t << "  " << lp << "  " << rp << "  " << i + j << endl;
  //     R += 1.0 * rp / pw2[j + 1];
  //   }
  //   ans += arr[t] * L * R;
  // }
  printf("%.15lf\n", (double) ans / n / n);
  return 0;
}