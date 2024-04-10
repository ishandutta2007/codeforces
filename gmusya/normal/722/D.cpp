#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set <int> a;
  while (n--) {
    int x;
    cin >> x;
    a.insert(x);
  }
  vector <int> ans;
  while (!a.empty()) {
    int val = *a.rbegin();
    a.erase(val);
    int newval = val / 2;
    while (a.find(newval) != a.end() && newval > 0)
      newval /= 2;
    if (!newval)
      ans.push_back(val);
    else
      a.insert(newval);
  }
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}