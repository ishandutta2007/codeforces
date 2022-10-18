#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

map<string, vector<int>> f; 

bool used[1002];

vector<string> name, city;

string get(int i) {
  if (!used[i]) return name[i].substr(0, 3);
  return name[i].substr(0, 2) + string(1, city[i][0]);
}

int main() {
  int n;
  cin >> n;
  name.resize(n); city.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> name[i] >> city[i];
  }

  while (true) {
    f.clear();
    for (int i = 0; i < n; ++i)
      f[get(i)].push_back(i);

    if (f.size() == n) break;

    bool ok = false;
    for (auto p : f) {
      if (p.second.size() > 1) {
        for (int x : p.second) {
          if (!used[x]) {
            ok = true;

            used[x] = true;
          }
        }
      }
    }

    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i)
    cout << get(i) << endl;

  return 0;
}