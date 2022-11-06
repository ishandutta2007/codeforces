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

#define INFLL 1000000000000000000LL
#define MAXN 500000

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

template <typename T>
ostream& operator<<(ostream &out, const vector<T> &list) {
  out << "[";
  for (int i = 0; i < (int)list.size(); ++i) {
    if (i > 0) out << ", ";
    out << list[i];
  }
  out << "]";
  return out;
}

vector<lint> solve(int size, vector<int> delta) {
  vector<int> deltasum;
  deltasum.push_back(0);
  for (int i = 0; i < (int)delta.size(); ++i)
    deltasum.push_back(delta[i] + deltasum.back());

  vector<int> ascdeltasum;
  ascdeltasum.push_back(deltasum[0]);
  for (int i = 1; i < (int)deltasum.size(); ++i)
    if (deltasum[i] > ascdeltasum.back()) ascdeltasum.push_back(deltasum[i]);
    else ascdeltasum.push_back(ascdeltasum.back());

  vector<int> descdeltasum;
  descdeltasum.push_back(deltasum[0]);
  for (int i = 1; i < (int)deltasum.size(); ++i)
    if (deltasum[i] < descdeltasum.back()) descdeltasum.push_back(deltasum[i]);
    else descdeltasum.push_back(descdeltasum.back());

  assert(ascdeltasum.size() == delta.size()+1);
  assert(descdeltasum.size() == delta.size()+1);

  for (int &v : descdeltasum) {assert(v <= 0); v = -v;}
  
  swap(ascdeltasum, descdeltasum); // Oops

  vector<lint> result(size, INFLL);
  for (int i = 0; i < size; ++i) {
    int toleft = i, toright = size-1-i;
    int hitleft = upper_bound(ascdeltasum.begin(), ascdeltasum.end(), toleft) - ascdeltasum.begin();
    int hitright = upper_bound(descdeltasum.begin(), descdeltasum.end(), toright) - descdeltasum.begin();
    int hit = min(hitleft, hitright);
    if (hit == (int)delta.size()+1) {}
    else result[i] = hit;
  }

  int cycle = deltasum.back();

  if (cycle < 0) {
    for (int i = 0; i < size; ++i)
      if (result[i] == INFLL) {
    assert(i + cycle >= 0);
    result[i] = (lint)delta.size() + result[i + cycle];
      }
  } else if (cycle > 0) {
    for (int i = size-1; i >= 0; --i)
      if (result[i] == INFLL) {
    assert(i + cycle < size);
    result[i] = (lint)delta.size() + result[i + cycle];
      }
  }

  return result;
}

int main() {
  int n, height, width;
  static char seq[MAXN+1];
  scanf("%d %d %d %s", &n, &height, &width, seq);

  vector<int> deltah, deltav;
  for (int i = 0; i < n; ++i) {
    if (seq[i] == 'U') {deltav.push_back(-1); deltah.push_back(0);}
    else if (seq[i] == 'D') {deltav.push_back(1); deltah.push_back(0);}
    else if (seq[i] == 'L') {deltah.push_back(-1); deltav.push_back(0);}
    else if (seq[i] == 'R') {deltah.push_back(1); deltav.push_back(0);}
    else assert(0);
  }

  int result;
  vector<lint> reth = solve(width, deltah);
  vector<lint> retv = solve(height, deltav);

  sort(reth.begin(), reth.end());
  sort(retv.begin(), retv.end());
  
  if (reth.back() == INFLL && retv.back() == INFLL) result = -1;
  else {
    result = 0;
    int j = -1;
    for (int i = 0; i < (int)reth.size(); ++i) {
      while (j+1 < (int)retv.size() && retv[j+1] <= reth[i]) ++j;
      result = (result + (lint)(retv.size()-1-j) * reth[i]) % mod;
    }
    int i = -1;
    for (int j = 0; j < (int)retv.size(); ++j) {
      while (i+1 < (int)reth.size() && reth[i+1] < retv[j]) ++i;
      result = (result + (lint)(reth.size()-1-i) * retv[j]) % mod;
    }
  }

  printf("%d\n", result);
  
  return 0;
}