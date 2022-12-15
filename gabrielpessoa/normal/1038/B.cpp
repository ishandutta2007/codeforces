#include <bits/stdc++.h>
using namespace std;

int qnt[300];

int main() {
  int n;
  cin >> n;
  if(n <= 2) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << 1 << ' ' << n << endl;
    cout << n - 1;
    for(int i = 1; i < n; i++) cout << ' ' << i;
    cout << endl;
  }
  return 0;
}