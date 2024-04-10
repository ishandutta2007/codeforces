#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

map<string, vector<string>> f;

int dfs(string s) {
  int ret = 0;
  for (auto x : f[s])
    ret = max(ret, dfs(x));
  return ret + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s1, s2, s3;
    cin >> s1 >> s3 >> s2;
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    f[s2].push_back(s1);
  }
  cout << dfs("polycarp") << endl;
  return 0;
}