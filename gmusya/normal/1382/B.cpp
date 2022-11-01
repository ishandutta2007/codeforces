#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int id = 0;
    while (id < n && a[id] == 1) id++;
    if (id == n) {
      if (n % 2) cout << "First\n";
      else cout << "Second\n";
    }
    else {
      if (id % 2) cout << "Second\n";
      else cout << "First\n";
    }
  }
  return 0;
}