#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int z = 0, o = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'z') z++;
    else if(s[i] == 'n') o++;
  }
  while(o--) cout << 1 << ' ';
  while(z--) cout << 0 << ' ';
}