#include <bits/stdc++.h>
using namespace std;

int ask(int t, int i, int j, int x)
{
  cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
  cout.flush();
  int res;
  cin >> res;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
      st.push(i);

    while (st.size() >= 2)
    {
      int i = st.top();
      st.pop();
      int j = st.top();
      st.pop();
      int u = ask(2, i, j, 1);
      if (u > 2) // happy case
      {
        int v = ask(1, i, j, n - 1);
        if (v < n - 1)
        {
          int w = ask(2, i, j, u);
          a[i] = u;
          a[j] = v;
          if (w != u)
            swap(a[i], a[j]);
        }
        else // [n - 1, n]
        {
          if (v == n) // a[j] = n
          {
            a[j] = n;
            st.push(i);
            continue;
          }

          int w = ask(1, j, i, n - 1);
          if (w == n) // a[i] = n
          {
            a[i] = n;
            st.push(j);
            continue;
          }

          int y = ask(1, i, j, n - 2);
          if (y == n - 1) // a[j] = n - 1
          {
            a[j] = n - 1;
            st.push(i);
          }
          else // a[i] = n - 1;
          {
            a[i] = n - 1;
            st.push(j);
          }
        }
      }
      else // [1, 2]
      {
        if (u == 1) // a[i] = 1
        {
          a[i] = 1;
          st.push(j);
          continue;
        }

        int v = ask(2, j, i, 1);
        if (v == 1) // a[j] = 1
        {
          a[j] = 1;
          st.push(i);
          continue;
        }

        int w = ask(2, i, j, 2);
        if (w == 2) // a[i] = 2
        {
          a[i] = 2;
          st.push(j);
        }
        else // a[j] = 2
        {
          a[j] = 2;
          st.push(i);
        }
      }
    }

    if (!st.empty())
    {
      int i = st.top();
      a[i] = n * (n + 1) / 2 - accumulate(a.begin(), a.end(), 0);
    }

    cout << "!";
    for (int x : a)
      cout << ' ' << x;
    cout << endl;
    cout.flush();
  }
}