#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const string x = "aeiou";

int main() {
  string a, b;
  cin >> a >> b;
  if(a.size() != b.size()) {
    cout << "No\n";
    return 0;
  }
  for(int i = 0; i < a.size(); i++) {
    auto aa = x.find(a[i]) != string::npos;
    auto bb = x.find(b[i]) != string::npos;
    if(aa != bb) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}