#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <cstring>

#define INF 1000000000

using namespace std;

typedef long long lint;

int greedy(int b0, int b1, int b2) {
  int l = 0, r = 200000;
  while (l < r) {
    int m = (l+r)/2;

    int remain, cantake;
    
    int h0 = b0, h1 = b1, h2 = b2;

    {
      remain = m;
      
      cantake = min(remain, h2);
      h2 -= cantake, remain -= cantake;
      cantake = min(remain, h1);
      h1 -= cantake, remain -= cantake;
      cantake = min(remain, h0);
      h0 -= cantake, remain -= cantake;
    }
    {
      remain = m;
      
      cantake = min(remain, h1);
      h1 -= cantake, remain -= cantake;
      cantake = min(remain, h0);
      h0 -= cantake, remain -= cantake;
    }
    {
      remain = m;
      
      cantake = min(remain, h0);
      h0 -= cantake, remain -= cantake;
    }

    if (h0 == 0 && h1 == 0 && h2 == 0) r = m;
    else l = m+1;
  }

  return l;
}

inline void take(vector<int> &many, int much, int upto) {
  for (int i = upto; i >= 0; --i) {
    int maxtake = min(much, many[i]);
    many[i] -= maxtake;
    much -= maxtake;
  }
}

int solve2a(int a, int b, int c, vector<int> &vals) {
  vector<int> many(6, 0);
  for (int v : vals) {
    if (v <= a) ++many[0];
    else if (v <= b) ++many[1];
    else if (v <= c) ++many[2];
    else if (v <= a+b) ++many[3];
    else if (v <= a+c) ++many[4];
    else if (v <= b+c) ++many[5];
    else assert(0);
  }

  int prefix = 0;
  prefix += many[5]; take(many, many[5], 0);
  prefix += many[4]; take(many, many[4], 1);
  prefix += many[3]; take(many, many[3], 2);

  int result = INF;
  
  for (int nab = 0; nab <= many[2]; ++nab) {
    int res = 0;
    vector<int> manyback = many;

    res += nab;
    many[2] -= nab;
    take(many, nab, 2);

    res += greedy(many[0], many[1], many[2]);

    many = manyback;
    result = min(result, res);
  }

  return prefix + result;
}

int solve2b(int a, int b, int c, vector<int> &vals) {
  vector<int> many(6, 0);
  for (int v : vals) {
    if (v <= a) ++many[0];
    else if (v <= b) ++many[1];
    else if (v <= a+b) ++many[2];
    else if (v <= c) ++many[3];
    else if (v <= a+c) ++many[4];
    else if (v <= b+c) ++many[5];
    else assert(0);
  }

  int prefix = 0;
  prefix += many[5]; take(many, many[5], 0);
  prefix += many[4]; take(many, many[4], 1);

  int result = INF;
  
  for (int nab = 0; nab <= many[2]; ++nab) {
    int res = 0;
    vector<int> manyback = many;

    res += nab;
    many[2] -= nab;
    take(many, nab, 3);

    res += greedy(many[0], many[1], many[2]+many[3]);

    many = manyback;
    result = min(result, res);
  }

  return prefix + result;
}

int solve2(int a, int b, int c, vector<int> &v) {
  if (a+b >= c) return solve2a(a, b, c, v);
  else return solve2b(a, b, c, v);
}

int solve(int a, int b, int c, vector<int> &v) {
  sort(v.begin(), v.end());
  if (v.back() > a+b+c) return -1;
  int result = 0;
  while (!v.empty() && v.back() > b+c) {
    ++result;
    v.pop_back();
  }
  if (!v.empty()) result += solve2(a, b, c, v);
  return result;
}

int main() {
  int n, s[3];
  scanf("%d %d %d %d", &n, &s[0], &s[1], &s[2]);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(s, s+3);
  printf("%d\n", solve(s[0], s[1], s[2], v));
  
  return 0;
}