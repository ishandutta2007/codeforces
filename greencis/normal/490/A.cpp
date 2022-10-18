#include<bits/stdc++.h>
using namespace std;

vector<int> a,b,c;
int n,x;

int main() {
 cin >> n;
 for (int i = 1; i <= n; ++i) {
  cin >> x;
  if (x == 1) a.push_back(i);
  else if (x == 2) b.push_back(i);
  else c.push_back(i);
 }
 int sz = min(a.size(), min(b.size(), c.size()));
 cout << sz << endl;
 for (int i = 0; i < sz; ++i) cout << a[i] << " " << b[i] << " " << c[i] << endl;
 return 0;
}