#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int A, B, k;
    cin >> A >> B >> k;
    vector <int> a(k), b(k);
    for (int i = 0; i < k; i++)
      cin >> a[i];
    for (int i = 0; i < k; i++)
      cin >> b[i];
    for (int i = 0; i < k; i++)
      a[i]--, b[i]--;
    vector <int> cnta(A), cntb(B);
    for (int i = 0; i < k; i++)
      cnta[a[i]]++, cntb[b[i]]++;
    long long ans = 0;
    for (int i = 0; i < k; i++)
      ans += k - (cnta[a[i]] + cntb[b[i]]) + 1;
    cout << ans / 2 << '\n';
  }
  return 0;
}