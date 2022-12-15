#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  int x = 0, y = 0, z = 0;
  for(int i = 1; i <= 6; i++) {
    if(abs(i-a) < abs(i-b)) x++;
    else if(abs(i-a) == abs(i-b)) y++;
    else z++;
  }
  cout << x << ' ' << y << ' ' << z << endl;
}