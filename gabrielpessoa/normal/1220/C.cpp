#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;

main() {
  char lo = 'z';
  string s;
  cin >> s;
  for(char c : s) {
    lo = min(c, lo);
    if(c == lo) {
      cout << "Mike\n";
    } else {
      cout << "Ann\n";
    }
  }
}