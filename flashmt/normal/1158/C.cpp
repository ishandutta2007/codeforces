#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > edges;
int ans[500500], value;

void go(int x)
{
  ans[x] = value--;
  for (int y : edges[x])
    go(y);
}

int main()
{
  ios::sync_with_stdio(0);
  int test, n, next;
  cin >> test;
  while (test--)
  {
    cin >> n;
    edges.assign(n + 2, {});
    vector < array<int, 3> > events;
    for (int i = 1; i <= n; i++)
    {
      cin >> next;  
      if (next < 0)
        next = i + 1;
      edges[next].push_back(i);
      events.push_back({i, 1, -i});
      events.push_back({next, 0, -i});
    }

    vector < array<int, 3> > st;
    sort(events.begin(), events.end());
    int isGood = 1;
    for (auto e : events)
      if (e[1]) st.push_back(e);
      else if (st.empty() || st.back()[2] != e[2]) 
      {
        isGood = 0;
        break;
      }
      else st.pop_back();

    value = n + 1;
    go(n + 1);

    if (!isGood) cout << "-1\n";
    else
      for (int i = 1; i <= n; i++)
        cout << ans[i] << (i == n ? '\n' : ' ');
  }
}