/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/H
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const int C = 200;

#ifdef _DEBUG

const int MAX_QUERIES = 4;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int RandInt(int low, int high) {
  return low + (rng() % (high - low + 1));
}

int L, R, B, T;
int _rem;

void SetupJudge() {
  L = RandInt(1, C - 1);
  R = RandInt(L + 1, C);
  B = RandInt(1, C - 1);
  T = RandInt(B + 1, C);
  _rem = MAX_QUERIES;
}

int Ask(const vector<pair<int, int>>& pts) {
  assert(--_rem >= 0);
  int r = 0;
  for (const auto [x, y] : pts) {
    if (L <= x && x <= R && B <= y && y <= T) {
      ++r;
    }
  }
  return r;
}

void Answer(int p) {
  assert(p == 2 * (R - L + T - B));
}

#else

int Ask(const vector<pair<int, int>>& pts) {
  int k = (int) pts.size();
  cout << "? " << k << endl;
  for (int i = 0; i < k; i++) {
    if (i > 0) {
      cout << ' ';
    }
    auto [x, y] = pts[i];
    cout << x << ' ' << y;
  }
  cout << endl;
  int r;
  cin >> r;
  return r;
}

void Answer(int p) {
  cout << "! " << p << endl;
}

#endif

map<int, int> mp;

int Ask(int stepX) {
  if (stepX > C) {
    return 0;
  }
  {
    auto it = mp.find(stepX);
    if (it != mp.end()) {
      return it->second;
    }
  }
  vector<pair<int, int>> v;
  for (int i = 1; i <= C; i += stepX) {
    for (int j = 1; j <= C; j++) {
      v.emplace_back(i, j);
    }
  }
  return mp[stepX] = Ask(v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  SetupJudge();
#endif
  
  int area = Ask(1); // assume the points are actually unit squares
  int low = 0, high = 7;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int step = (1 << mid);
    if (Ask(step) * step == area) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  int e2 = low;
  int h = abs(2 * Ask(1 << (e2 + 1)) - Ask(1 << e2));
  int w = area / h;
  int ans = 2 * (w - 1 + h - 1); // convert back to points
  Answer(ans);
  return 0;
}