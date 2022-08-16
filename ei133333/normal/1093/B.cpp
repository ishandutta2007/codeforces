#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int T;
  cin >> T;
  while(T--) {
    string x;
    cin >> x;
    sort(begin(x), end(x));

    string y = x;
    reverse(begin(y), end(y));
    if(x != y) {
      cout << x << endl;
    } else {
      cout << -1 << endl;
    }
  }
}