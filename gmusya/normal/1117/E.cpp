#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <set>

using namespace std;

int n, m;
vector <bool> used;
vector <int> mt, p;
vector <set <int>> g;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 gen(time(0));
  string s;
  cin >> s;
  int n = s.size();
  g.resize(n);
  vector <string> arr;
  for (int it = 0; it < 3; it++) {
    string t;
    for (int i = 0; i < n; i++) {
      int x;
      if (it == 0)
        x = i % 26;
      if (it == 1)
        x = i / 26 % 26;
      if (it == 2)
        x = i / 26 / 26 % 26;
      t += (x + 'a');
    }
    cout << "? " << t << endl;
    string a;
    cin >> a;
    arr.push_back(a);
  }
  vector <int> p(n);
  vector <char> ans(n);
  for (int i = 0; i < n; i++)
    ans[(arr[0][i] - 'a') + (arr[1][i] - 'a') * 26 + (arr[2][i] - 'a') * 26 * 26] = s[i];
  cout << "! ";
  for (int i = 0; i < n; i++)
    cout << ans[i];
  return 0;
}