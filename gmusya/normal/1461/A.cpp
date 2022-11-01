#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <char> arr(n);
    for (int i = 0; i < k; i++)
      arr[i] = 'a';
    int it = 1;
    for (int i = k; i < n; i++) {
      arr[i] = 'a' + it;
      it++;
      if (it == 3)
        it = 0;
    }
    for (auto &now : arr)
      cout << now;
    cout << '\n';
  }
  return 0;
}