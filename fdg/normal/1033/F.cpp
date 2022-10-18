#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int vals[(1<<12) + 5];

int mem[1<<24];
bool used[1<<24];

int setDigit(int mask, int val, int pos) {
  pos <<= 1;
  return (mask & (~(3 << pos))) | (val << pos);
}

void setDigitClean(int &mask, int val, int pos) {
  pos <<= 1;
  mask |= (val << pos);
}

bool isZero(char c, int a, int b) {
  if (c == 'A') return (a & b) == 0;
  if (c == 'O') return (a | b) == 0;
  if (c == 'X') return (a ^ b) == 0;

  return !isZero(c - 'a' + 'A', a ,b);
}

void build(string s, int res[1<<6], int isGood[1<<6]) {
  for (int a = 0; a < (1 << s.size()); ++a) {
      int mask = 0, good = true;
      for (int i = 0; i < s.size() && good; ++i) {
        bool ok0 = isZero(s[i], (a >> i) & 1, 0);
        bool ok1 = isZero(s[i], (a >> i) & 1, 1);

        setDigitClean(mask, ((ok0 && ok1) ? 3 : (ok1 ? 1 : 0)), i);

        if (!ok0 && !ok1) good = false;
      }
      
      res[a] = mask;
      isGood[a] = good;
    }
}

vector<int> q;

int main() {
  ios::sync_with_stdio(false);

  int w, n, m;
  cin >> w >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vals[x]++;
  }

  for (int i = 0; i < (1 << w); ++i) {
    if (vals[i] == 0) continue;

    int mask = 0;
    for (int j = 0; j < w; ++j) {
      mask = setDigit(mask, (i >> j) & 1, j);
    }
    q.push_back(mask);
    used[mask] = true;
    mem[mask] = vals[i];
  }

  for (int bt = 0; bt < w; ++bt) {
    for (int e = q.size() - 1; e >= 0; --e) {
      int cur = q[e];
      if (mem[cur] == 0) continue;

      int next = setDigit(cur, 3, bt);
      if (next != cur) {
        mem[next] += mem[cur];
      
        if (!used[next]) {
          q.push_back(next);
          used[next] = true;
        }
      }
    }
  }

  // for (int i = 0; i < (1 << (2 * w)); ++i)
  //   if (mem[i] != 0)
  //     cout << i << "  " << mem[i] << endl;

  int l[1<<6], r[1<<6], goodL[1<<6], goodR[1<<6];

  for (int q = 0; q < m; ++q) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    int half = w / 2;
    build(s.substr(0, half), l, goodL);
    build(s.substr(half, w - half), r, goodR);


    int ans = 0;
    for (int a = 0; a < (1 << w); ++a) {
      if (vals[a] == 0) continue;

      // int mask = 0, good = true;
      // for (int i = 0; i < w && good; ++i) {
      //   bool ok0 = isZero(s[i], (a >> i) & 1, 0);
      //   bool ok1 = isZero(s[i], (a >> i) & 1, 1);

      //   setDigitClean(mask, ((ok0 && ok1) ? 3 : (ok1 ? 1 : 0)), i);

      //   if (!ok0 && !ok1) good = false;
      // }
      // if (!good) continue;

      bool good = goodL[a & ((1 << half) - 1)] && goodR[a >> half];
      if (good) {
        int mask = l[a & ((1 << half) - 1)] + (r[a >> half] << (2 * half));
        ans += vals[a] * mem[mask];
      }
    }
    cout << ans << endl;
  }

  return 0;
}