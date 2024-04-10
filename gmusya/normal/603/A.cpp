#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <char> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  int ans = 0;
  for (int i = 1; i < n; i++)
    ans += (c[i] != c[i - 1]);
  cout << min(ans + 3, n);
  return 0;
}