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

int hashof(const string &s) {
  int res = 0;
  for (char c : s)
    res = ((lint)res * 239 + c) % 1000000021;
  return res;
}

int hashof(const set<pair<int, string>> &sset) {
  int res = 0;
  for (auto &it : sset)
    res = ((lint)res * 277 + it.first) % 1000000033;
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  map<pair<int, string>, set<pair<int, string>>> paths;
  for (int i = 0; i < n; ++i) {
    char hostnamecstr[21], pathcstr[22] = {};
    scanf(" http://%20[^ /\n]%21[^\n]", hostnamecstr, pathcstr);
    scanf("\n");
    string hostname(hostnamecstr), path(pathcstr);
    int hostnamehash = hashof(hostname), pathhash = hashof(path);
    paths[{hostnamehash, move(hostname)}].insert({pathhash, move(path)});
  }

  map<pair<int, set<pair<int, string>>>, vector<string>> hostnames;
  for (auto &it : paths) {
    const string &hostname = it.first.second;
    set<pair<int, string>> &pathset = it.second;
    int pathsethash = hashof(pathset);
    hostnames[{pathsethash, move(pathset)}].push_back(hostname);
  }

  vector<vector<string>> result;
  for (auto &it : hostnames) {
    vector<string> &group = it.second;
    if (group.size() >= 2) result.push_back(move(group));
  }

  printf("%d\n", (int)result.size());
  for (vector<string> &group : result) {
    for (int i = 0; i < (int)group.size(); ++i) {
      if (i > 0) printf(" ");
      printf("http://%s", group[i].c_str());
    }
    printf("\n");
  }
  
  return 0;
}