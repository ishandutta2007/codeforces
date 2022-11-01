#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <int> b;
  for (int i = 0; i + 1 < n; i++)
    if (a[i + 1] == 1)
      b.push_back(a[i]);
  b.push_back(a.back());
  cout << b.size() << '\n';
  for (int x : b)
    cout << x << ' ';
  return 0;
}