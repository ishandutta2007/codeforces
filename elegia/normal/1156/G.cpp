#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;

char s[100];
bool ops[256];
int relabel[N * 6];
int va[N * 6][2];
int typ[N * 6];
bool vis[N * 6], beres[N * 6];
string detail[N * 6];
map<string, int> ex;
map<pair<pair<int, int>, int>, int> rel;
vector<string> ans;

char usea;
int usev;
string nxtvar() {
  while (true) {
    string cur = string() + usea + to_string(usev);
    if (!ex.count(cur)) {
      ex.insert(make_pair(cur, 0));
      return cur;
    }
    if (++usev == 1000) {
      usev = 0;
      ++usea;
    }
  }
}

int strcnt;
int gid(const string& str) {
  auto it = ex.find(str);
  if (it != ex.end())
    return it->second;
  ex.insert(make_pair(str, ++strcnt));
  detail[strcnt] = str;
  return strcnt;
}

int nid(const string& str) {
  detail[++strcnt] = str;
  return ex[str] = strcnt;
}

void dfs(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  if (typ[u] == 0) {
    relabel[u] = u;
    return;
  }
  if (typ[u] == -1) {
    if (beres[u]) {
      if (typ[va[u][0]]) {
        beres[va[u][0]] = true;
      } else {
        if (detail[va[u][0]] != "res")
          ans.push_back("res=" + detail[va[u][0]]);
        return;
      }
    }
    dfs(va[u][0]);
    relabel[u] = relabel[va[u][0]];
    return;
  }
  dfs(va[u][0]);
  dfs(va[u][1]);
  pair<pair<int, int>, int> spec(make_pair(relabel[va[u][0]], relabel[va[u][1]]), typ[u]);
  relabel[u] = u;
  if (!rel.count(spec)) {
    rel.insert(make_pair(spec, u));
    detail[u] = nxtvar();
    ans.push_back((beres[u] ? string("res") : detail[u]) + "=" + detail[relabel[va[u][0]]] + char(typ[u]) + detail[relabel[va[u][1]]]);
  } else
    relabel[u] = rel[spec];
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  usea = 'a';
  usev = 0;
  ops['$'] = true;
  ops['^'] = true;
  ops['#'] = true;
  ops['&'] = true;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    char *p1 = s, *p2;
    while (*p1 != '=')
      ++p1;
    string a(s, p1);
    p2 = p1;
    while (!ops[*p2] && *p2)
      ++p2;
    if (ops[*p2]) {
      string b(p1 + 1, p2), c(p2 + 1);
      int bi = gid(b), ci = gid(c);
      int ai = nid(a);
      typ[ai] = *p2;
      va[ai][0] = bi;
      va[ai][1] = ci;
    } else {
      string b(p1 + 1);
      int bi = gid(b);
      int ai = nid(a);
      typ[ai] = -1;
      va[ai][0] = bi;
    }
  }
  int resi = gid("res");
  beres[resi] = true;
  dfs(resi);
  printf("%lu\n", ans.size());
  for (auto str : ans)
    puts(str.c_str());

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}