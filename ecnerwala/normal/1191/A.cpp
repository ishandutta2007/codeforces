#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x; cin >> x;
  if (x % 4 == 1) cout << 0 << ' ' << 'A' << '\n';
  else if (x % 4 == 2) cout << 1 << ' ' << 'B' << '\n';
  else if (x % 4 == 3) cout << 2 << ' ' << 'A' << '\n';
  else if (x % 4 == 0) cout << 1 << ' ' << 'A' << '\n';
  else assert(false);
}