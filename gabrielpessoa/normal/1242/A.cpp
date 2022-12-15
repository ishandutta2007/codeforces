#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2e6+5;
int ds[ms], sz[ms], n;

void dsBuild() {
  for(int i = 0; i < n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
}

int dsFind(int i) {
  if(ds[i] != i) ds[i] = dsFind(ds[i]);
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); b = dsFind(b);
  if(sz[a] < sz[b]) swap(a, b);
  if(a != b) sz[a] += sz[b];
  ds[b] = a;
}
int arr[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int k;
  cin >> k;
  if(k == 1) {
    cout << 1 << '\n';
    return 0;
  }
  int start = k;
  vector<int> divs;
  for(int i = 2; i * i <= k; i++) {
    if(k % i == 0) {
      divs.emplace_back(i);
      while(k % i == 0) k /= i;
      // cout << "div " << i << endl;
    }
  }
  if(k > 1) divs.push_back(k);
  if(divs.size() == 1) {
    cout << divs[0] << '\n';
  } else {
    cout << 1 << '\n';
  }
  return 0;
  k = start;
  if(divs[0] == start) {
    cout << start << '\n';
    return 0;
  }
  n = 2e6+5;
  dsBuild();
  for(int i = 1; i < min(n, k+1); i++) {
    for(int j : divs) {
      if(i+j <= k && i+j < n) {
        dsUnion(i, i+j);
        // cout << "unindo " << i << " " << i+j << '\n';
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < min(n, k+1); i++) {
    if(dsFind(i) == i) ans++;
  }
  cout << ans << '\n';
}