#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define MAXN 200000

using namespace std;

typedef long long lint;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int good[2*MAXN], many[2*MAXN];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  lint result = 0;
  
  map<int, vector<int>> sizeswithg;
  for (int s = 1; s < n; ++s) sizeswithg[gcd(s, n)].push_back(s);

  vector<int> bucket(n);
  
  for (const pair<int, vector<int>> &it : sizeswithg) {
    int g = it.first;
    const vector<int> &sizes = it.second;

    for (int i = 0; i < g; ++i) bucket[i] = 0;
    for (int i = 0; i < n; ++i)
      bucket[i % g] = max(bucket[i % g], a[i]);
    for (int i = 0; i < n; ++i)
      good[i] = good[i + n] = (bucket[i % g] == a[i]);

    many[2*n-1] = good[2*n-1];
    for (int i = 2*n-2; i >= 0; --i) {
      if (good[i]) many[i] = 1 + many[i+1];
      else many[i] = 0;
    }

    const int ns = sizes.size();
    int j = -1;
    
    for (int i = 2*n-1; i >= 0; --i) {
      while (j >= 0 && many[i] < sizes[j]) --j;
      while (j+1 < ns && many[i] >= sizes[j+1]) ++j;
      
      if (i < n)
	result += j+1;
    }
  }

  cout << result << endl;
  
  return 0;
}