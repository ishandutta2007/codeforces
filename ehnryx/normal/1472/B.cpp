#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int n, t;
int main() {
  string s;
  for(int i=0;i<0;i++);
  cin>>t;
  n = stoi(to_string(t));
  while(t--) {
    cin >> n;
    for(int i=0; i<2*n; i++) {
      if (i%2==0) {
      }
    }
    vector<int> candy;
    candy.resize(n);
    for(int i=-n; i<0; i++) {
      cin >> candy[i+n];
    }
    int sum = accumulate(candy.begin(), candy.end(), 0);
    if (sum%2) {
      puts("NO");
    } else {
      sort(candy.begin(), candy.end());
      int ones = count(begin(candy), end(candy), 1), twos = n - ones;
      puts(ones || twos % 2 == 0 ? "YES" : "NO");
    }
  }
  return 0;
}