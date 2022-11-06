#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct task_t {
  lint da, db, dc;
};

struct halfsol {
  lint changeb, changec, a;
  int mask;
  bool operator < (const halfsol &o) const {
    if (changeb != o.changeb) return changeb < o.changeb;
    if (changec != o.changec) return changec < o.changec;
    return a < o.a;
  }
};

void solve(vector<task_t> &tasks, int l, int r, vector<halfsol> &result, halfsol sol) {
  if (l == r) result.push_back(sol);
  else {
    int mask = sol.mask;
    lint a = sol.a, da = tasks[l].da, db = tasks[l].db, dc = tasks[l].dc;
    solve(tasks, l+1, r, result, {sol.changeb - da + db, sol.changec - da, a + da, (mask<<2) | 1}); // a, b
    solve(tasks, l+1, r, result, {sol.changeb - da, sol.changec - da + dc, a + da, (mask<<2) | 2}); // a, c
    solve(tasks, l+1, r, result, {sol.changeb + db, sol.changec + dc, a, (mask<<2) | 3}); // b, c
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<task_t> tasks(n);
  for (task_t &task : tasks) scanf("%lld %lld %lld", &task.da, &task.db, &task.dc);
  int mid = n/2;

  vector<halfsol> left, right;
  solve(tasks, 0, mid, left, {0LL, 0LL, 0LL, 0});
  solve(tasks, mid, n, right, {0LL, 0LL, 0LL, 0});

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  lint result = LLONG_MIN;
  int leftmask = -1, rightmask = -1;
  int j = right.size()-1;
  for (int i = 0; i < (int)left.size(); ++i) {
    halfsol want = {-left[i].changeb, -left[i].changec, 0, -1};
    while (j >= 0 && (right[j].changeb > want.changeb || (right[j].changeb == want.changeb && right[j].changec > want.changec))) --j;
    if (j >= 0 && right[j].changeb == want.changeb && right[j].changec == want.changec) {
      lint res = left[i].a + right[j].a;
      if (res > result) {
	result = res;
	leftmask = left[i].mask, rightmask = right[j].mask;
      }
    }
  }

  if (result == LLONG_MIN) printf("Impossible\n");
  else {
    vector<int> guys(n);
    for (int i = mid-1; i >= 0; --i) {
      guys[i] = leftmask & 3;
      leftmask >>= 2;
    }
    for (int i = n-1; i >= mid; --i) {
      guys[i] = rightmask & 3;
      rightmask >>= 2;
    }
    for (int i = 0; i < n; ++i) {
      if (guys[i] == 1) printf("LM\n");
      else if (guys[i] == 2) printf("LW\n");
      else printf("MW\n");
    }
  }

  return 0;
}