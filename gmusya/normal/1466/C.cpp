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
    string s;
    cin >> s;
    int n = s.size();
    vector <int> arr(n + 5, -2);
    for (int i = 0; i < n; i++)
      arr[i + 2] = s[i] - 'a';
    int cnt = 0;
    for (int i = 2; i < n + 2; i++) {
      if (arr[i] < 0)
        continue;
      if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
        arr[i + 1] = -3;
        arr[i + 2] = -4;
        i += 2;
        cnt += 2;
        continue;
      }
      if (arr[i] == arr[i + 2]) {
        arr[i + 2] = -5;
        cnt++;
        continue;
      }
      if (arr[i] == arr[i + 1]) {
        arr[i + 1] = -6;
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}