#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    vector <int> ans(n);
    ans[0] = 0;
    int it0 = 0, it1 = 1;
    while (it1 < n) {
      ans[it1] = ans[it0] + 1;
      if (it1 + 1 < n && a[it1] > a[it1 + 1])
        it0++;
      it1++;
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
      answer = max(answer, ans[i]);
    cout << answer << '\n';
  }
  return 0;
}