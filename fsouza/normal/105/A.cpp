#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  double k;

  scanf("%d %d %lf", &n, &m, &k);
  
  map<string, int> skill;

  for (int i = 0; i < n; i++) {
    char _name[32];
    int v;
    scanf(" %s %d", _name, &v);
    string name(_name);

    int v2 = (int)floor(v * k + 1e-9);

    if (v2 >= 100)
      skill[name] = v2;
  }

  for (int i = 0; i < m; i++) {
    char _name[32];
    scanf(" %s", _name);
    string name(_name);
    skill[name] = max(skill[name], 0);
  }

  printf("%d\n", (int)skill.size());
  for (map<string, int>::iterator it = skill.begin(); it != skill.end(); it++)
    printf("%s %d\n", it -> first.c_str(), it -> second);

  return 0;
}