#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h;
  cin >> h;
  vector <int> a(h + 1);
  for (int i = 0; i <= h; i++)
    cin >> a[i];
  int id = -1;
  for (int i = 0; i < h; i++)
    if (a[i] > 1 && a[i + 1] > 1)
      id = i + 1;
  if (id == -1) {
    cout << "perfect";
  } else {
    cout << "ambiguous\n";
    int sum = 0;
    vector <int> ans0, ans1;
    for (int i = 0; i <= h; i++) {
      for (int j = 0; j < a[i]; j++)
        ans0.push_back(sum);
      sum += a[i];
    }
    sum = 0;
    for (int i = 0; i <= h; i++) {
      if (i == id) {
        ans1.push_back(sum - 1);
        a[i]--;
      }
      for (int j = 0; j < a[i]; j++)
        ans1.push_back(sum);
      sum += a[i] + (i == id);
    }
    for (auto &now : ans0)
      cout << now << ' ';
    cout << '\n';
    for (auto &now : ans1)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}