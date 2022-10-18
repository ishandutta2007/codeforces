#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[150005];

vector<int> bad;

bool check(int i) {
  if (i & 1) {
    return arr[i] > arr[i + 1];
  }
  return arr[i] < arr[i + 1];
}

int n;
set<pair<int, int>> f;

void process(int x) {
  for (int i = 0; i < n; ++i) {
    int p1 = arr[x], p2 = arr[i];
    arr[x] = p2; arr[i] = p1;
    bool good = true;
    if (i + 1 < n) good = good && check(i);
    if (i + 2 < n) good = good && check(i + 1);
    if (i > 0) good = good && check(i - 1);
    if (x + 1 < n) good = good && check(x);
    if (x + 2 < n) good = good && check(x + 1);
    if (x > 0) good = good && check(x - 1);
    for (int e : bad) {
      if (!check(e) || e > 0 && !check(e - 1) || e + 2 < n && !check(e + 1)) {
        good = false;
        break;
      } 
    }
    if (good) {
      f.insert({min(x, i), max(x, i)});
    }
    arr[x] = p1; arr[i] = p2;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i + 1 < n; ++i) {
    if (!check(i))
      bad.push_back(i);
  }

  if (bad.size() > 7) {
    cout << 0 << endl;
    return 0;
  }

  process(bad[0]);
  process(bad[0] + 1);

  cout << f.size() << endl;
  return 0;
}