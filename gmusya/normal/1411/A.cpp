#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <char> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int cnt = 0;
    int it = n - 1;
    while (it >= 0 && s[it] == ')')
      it--, cnt++;
    if (cnt > n - cnt)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}