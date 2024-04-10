#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;

int ds[ms], sz[ms], n;

void dsBuild() {
  for(int i = 1; i <= n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
}

int dsFind(int i) {
  while(ds[i] != i) {
    ds[i] = ds[ds[i]];
    i = ds[i];
  }
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); 
  b = dsFind(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  ds[b] = a;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  dsBuild();
  while(m--) {
    int k;
    cin >> k;
    int x;
    if(k) cin >> x;
    for(int i = 1; i < k; i++) {
      int y;
      cin >> y;
      dsUnion(x, y);
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << sz[dsFind(i)] << ' ';
  }
  cout << endl;
}