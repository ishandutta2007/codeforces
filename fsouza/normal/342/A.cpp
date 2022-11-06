#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int n;
  map<int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    cnt[v]++;
  }

//  124, 126, 136;

  int a = cnt[4];
  int c = cnt[3];
  int b = cnt[6] - c;

  map<int, int> need;
  need[1] += a;
  need[2] += a;
  need[4] += a;
  need[1] += b;
  need[2] += b;
  need[6] += b;
  need[1] += c;
  need[3] += c;
  need[6] += c;

  bool ok = true;
  for (int i = 0; i < 10; i++)
    if (need[i] != cnt[i])
      ok = false;

  if (b < 0) ok = false;

  if (!ok) cout << -1 << endl;
  else {
    for (int i = 0; i < a; i++) {
      cout << "1 2 4" << endl;
    }
    for (int i = 0; i < b; i++) {
      cout << "1 2 6" << endl;
    }
    for (int i = 0; i < c; i++) {
      cout << "1 3 6" << endl;
    }
  }

  return 0;
}