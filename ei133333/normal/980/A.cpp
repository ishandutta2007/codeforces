#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  int sum = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'o') ++sum;
  }

  if(sum == 0 || s.size() % sum == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }


}