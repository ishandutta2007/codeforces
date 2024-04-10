#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a[200200];
  vector<int> id[200200];
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    id[a[i]].push_back(i);
  }

  vector<int> st;
  int ans = 0, maxCnt = 0;
  for (int i = 0; i < n; i++)
    if (id[a[i]].size() >= 2)
    {
      if (i == id[a[i]][0])
      {
        st.push_back(i);
        maxCnt = max(maxCnt, int(id[a[i]].size()));
      }
      else if (i == id[a[i]].back())
      {
        if (st.size() == 1)
        {
          ans += i - st[0] + 1 - maxCnt;
          maxCnt = 0;
        }
        st.pop_back();
      }
    }

  cout << ans << endl;
}