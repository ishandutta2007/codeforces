#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> l(n), st;
  for (int i = 0; i < n; i++)
  {
    while (!empty(st) && (a[i] | a[st.back()]) == a[i])
      st.pop_back();
    l[i] = empty(st) ? -1 : st.back();
    st.push_back(i);
  }

  long long ans = n * (n + 1LL) / 2;
  st.clear();
  for (int i = n - 1; i >= 0; i--)
  {
    while (!empty(st) && (a[i] | a[st.back()]) == a[i] && a[i] != a[st.back()])
      st.pop_back();
    int r = empty(st) ? n : st.back();
    st.push_back(i);
    ans -= 1LL * (i - l[i]) * (r - i);
  }

  cout << ans << endl;
}