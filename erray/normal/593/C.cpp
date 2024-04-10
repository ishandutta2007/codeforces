// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int foo;
    cin >> x[i] >> y[i] >> foo;
    x[i] /= 2;
    y[i] /= 2;
  }

  function<void(int, vector<int>)> solve = [&](int cur, const vector<int>& a) {
    if (cur == (int) a.size()) {
      return;
    }
    if (cur) {
      cout << '+';
    }
    cout << "(";
    cout << a[cur] << "*(";
    cout << "(1-abs((t-";
    cout << cur << ")))+abs((";
    cout << "abs((t-";
    cout << cur << "))-1))))";
    if (cur) {
      cout << ')';
    }
    solve(cur + 1, a);
  };
  
  cout << string(n - 1, '(');
  solve(0, x);
  cout << '\n';
  cout << string(n - 1, '(');
  solve(0, y);

}