#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int b, g;
  cin >> b;
  vector <bool> arr(n), brr(m);
  while (b--) {
    int x;
    cin >> x;
    arr[x] = true;
  }
  cin >> g;
  while (g--) {
    int x;
    cin >> x;
    brr[x] = true;
  }
  int it = 0;
  while (clock() * 1.0 / CLOCKS_PER_SEC < 1.9) {
    int i = it % n, j = it % m;
    bool res = (arr[i] | brr[j]);
    arr[i] = res;
    brr[j] = res;
    it++;
  }
  for (int i = 0; i < n; i++)
    if (!arr[i]) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";
  return 0;
}