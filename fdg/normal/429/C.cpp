#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int cnt[25] = {0};
set<vector<int> > f;
int it = 0;

void go(vector<int> v, bool init = false) {
  // ++it;
  if (f.count(v)) return;
  f.insert(v);
  if (v.size() == 0) {
    puts("YES");
    exit(0);
  }
  sort(v.begin(), v.end());
  int val = v.back();
  if (val == 1) {
    if (cnt[1] == v.size()) {
      puts("YES");
      exit(0);
    }
    return;
  }
  vector<int> tmp = v;
  tmp.pop_back();
  vector<int> tmp2;

  if (cnt[val]) {
    cnt[val]--;
    --val;
    for (int i = 1; i < val; ++i) {
      // if (i == 2 || val - i == 2) continue;
      tmp2 = tmp;
      tmp2.push_back(i);
      tmp2.push_back(val - i);
      go(tmp2); 
    }
    ++val;
    cnt[val]++;
  }
  
  if (init) return;

  for (int i = 1; i < val; ++i) {
    // if (i == 2 || val - i == 2) continue;
    tmp2 = tmp;
    tmp2.push_back(i);
    tmp2.push_back(val - i);
    go(tmp2); 
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  if (n == 1) {
    puts(cnt[1] ? "YES" : "NO");
    return 0;
  }
  if (n == 2) {
    puts("NO");
    return 0 ;
  }
  if (cnt[2] || cnt[n - 1] || cnt[n] == 0) {
    puts("NO");
    return 0;
  }
  go(vector<int>(1, n), true);
  puts("NO");
  // cout << it << endl;
  return 0;
}