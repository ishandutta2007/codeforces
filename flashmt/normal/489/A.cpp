#include <bits/stdc++.h>
using namespace std;

int n, flag[3030];
pair <int,int> a[3030];
vector < pair<int,int> > ans;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (!flag[i])
    {
      int x = i;
      vector <int> list;
      while (!flag[x])
      {
        flag[x] = 1;
        list.push_back(x);
        x = a[x].second;
      }
      
      for (int j = 0; j + 1 < int(list.size()); j++)
        ans.push_back(make_pair(list[j], list[j + 1]));
    }
    
  cout << ans.size() << endl;
  for (int i = 0; i < int(ans.size()); i++) 
    cout << ans[i].first << ' ' << ans[i].second << endl;
}