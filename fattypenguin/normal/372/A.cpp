#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cassert>
#include <queue>
#include <vector>
#define PB push_back
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(it, n) for (__typeof(n.begin()) it = n.begin(); it != n.end(); ++it)

using namespace std;

int a[500007];

int main() {
  int n;
  cin >> n;
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  priority_queue<int> q;
  int ans = 0;
  for (int i = n - 1; i >= n / 2; --i) {
    q.push(a[i]);
    ++ans;
  }
  for (int i = n / 2 - 1; i >= 0; --i) {
    if (q.size() && q.top() >= a[i] * 2) {
      q.pop();
    } else {
      q.push(a[i]);
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}