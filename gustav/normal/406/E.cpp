#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

#define MAXM 100005

int n, m;
int s[MAXM];
int f[MAXM];

struct sol {
  int val;
  llint cnt;
  sol(int val, llint cnt) : val(val), cnt(cnt) {}
};

sol operator+(sol a, sol b) {
  if (a.val > b.val) return a;
  if (b.val > a.val) return b;
  return sol(a.val, a.cnt + b.cnt);
}

llint choose3(llint n) {
  return n * (n - 1) * (n - 2) / 3 / 2;
}

void load(vector< int > &v, int type) {
  for (int i = 0; i < m; ++i)
    if (s[i] == type)
      v.pb(f[i]);
  sort(v.begin(), v.end());
}

sol only(int type) {
  vector< int > v;
  load(v, type);

  if (v.size() < 3) return sol(0, 0);

  llint cntmin = count_if(v.begin(), v.end(), [&](int x){
    return x == v[0];
  });
  llint cntmax = count_if(v.begin(), v.end(), [&](int x){
    return x == v.back();
  });

  if (v[0] == v.back())
    return sol(0, choose3(v.size()));

  return sol(v.back() - v[0], choose3(v.size()) 
         - choose3(v.size() - cntmin)
         - choose3(v.size() - cntmax)
         + choose3(v.size() - cntmin - cntmax));
}

sol outmix(int type) {
  vector< int > v, w;
  load(v, type);

  if (v.size() < 2) return sol(0, 0);
  if (v.size() == m) return sol(0, 0);
  
  llint cnt = 0; 
  int best = 2 * n + 1, F;
  for (int i = 0; i < m; ++i) {
    if (s[i] == type) continue;
    if (f[i] >= v[0] && f[i] <= v.back()) return sol(0, 0);

    int d = min(abs(v[0] - f[i]), abs(v.back() - f[i]));
    if (best > d) { best = d; F = f[i]; cnt = 0; }
    if (best == d) { ++cnt; }
  }
  
  llint cntmin = count_if(v.begin(), v.end(), [&](int x){
    return x == v[0];
  });

  llint cntmax = count_if(v.begin(), v.end(), [&](int x){
    return x == v.back();
  });

  if (F < v[0]) cnt = cnt * (cntmin * (v.size() - cntmin) + 
                             cntmin * (cntmin - 1) / 2);
  if (F > v.front()) cnt = cnt * (cntmax * (v.size() - cntmax) + 
                             cntmax * (cntmax - 1) / 2);

  return cnt ? sol(2 * n - best, cnt) : sol(0, 0);
}

sol inmix() {
  vector< int > v[2];
  load(v[0], 0); 
  load(v[1], 1); 

  auto get_le = [](vector< int > &v, int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
  };

  auto get_ge = [](vector< int > &v, int x) {
    return v.size() - (lower_bound(v.begin(), v.end(), x) - v.begin());
  };

  auto get_eq = [](vector< int > &v, int x) {
    return upper_bound(v.begin(), v.end(), x) - 
           lower_bound(v.begin(), v.end(), x);
  };

  llint cnt = 0;
  for (int i = 0; i < m; ++i) { 
    int t = 1 - s[i];
    llint le = get_le(v[t], f[i]);
    llint ge = get_ge(v[t], f[i]);
    llint eq = get_eq(v[t], f[i]);
    cnt += (le - eq) * (ge - eq);
    cnt += eq * (le + ge - 2 * eq);
    cnt += eq * (eq - 1) / 2;
  }

  return cnt ? sol(2 * n, cnt) : sol(0, 0);
}

sol case1() { return only(0) + only(1); }
sol case2() { return outmix(0) + outmix(1); }
sol case3() { return inmix(); } 

int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", s + i, f + i);
  }

  sol ans = case1() + case2() + case3();

  cout << ans.cnt << endl;

  return 0;
}