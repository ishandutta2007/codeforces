#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  int res = 0;
  int v = 0;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    if(a <= 0) continue;
    if(i < k || a >= v) v = a, res ++;
  }
  cout << res << '\n';
}