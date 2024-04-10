#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, w;
    cin >> n >> w;
    vector <pair <ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    {
      ll sum = 0;
      for (int i = 0; i < n; i++)
        sum += a[i].first;
      if (sum < (w + 1) / 2) {
        cout << -1 << '\n';
        continue;
      }
    }
    ll sum = 0;
    stack <int> st;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if ((w + 1) / 2 <= a[i].first && a[i].first <= w) {
        cout << 1 << '\n';
        cout << a[i].second + 1 << '\n';
        flag = true;
        break;
      }
    }
    if (flag)
      continue;
    for (int i = 0; i < n; i++) {
      st.push(i);
      sum += a[i].first;
      if ((w + 1) / 2 <= sum && sum <= w) {
        cout << st.size() << '\n';
        while (!st.empty()) {
          cout << a[st.top()].second + 1 << ' ';
          st.pop();
        }
        flag = true;
        break;
      }
      if (sum > w) {
        sum -= a[st.top()].first;
        st.pop();
      }
    }
    if (!flag)
      cout << -1 << '\n';
  }
  return 0;
}