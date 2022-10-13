#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s(n + 1);
  vector<int> st = {0};
  for (int i = 1; i <= n; i++)
  {
    int v;
    cin >> v;
    s[i] = s[i - 1] + v;

    while (size(st) >= 2)
    {
      int u = st[size(st) - 2], v = st[size(st) - 1];
      if ((s[i] - s[v]) * (v - u) > (s[v] - s[u]) * (i - v))
        break;
      st.pop_back();
    }
    st.push_back(i);
  }

  for (int i = 1; i < size(st); i++)
  {
    int u = st[i - 1], v = st[i];
    double ans = 1. * (s[v] - s[u]) / (v - u);
    for (int j = u; j < v; j++)
      cout << fixed << setprecision(9) << ans << '\n';
  }
}