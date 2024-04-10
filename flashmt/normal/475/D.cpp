#include <bits/stdc++.h>
using namespace std;

map <int,int> qId;
long long ans[300300];
int n, q, a[100100], queries[300300];

int getId(int x)
{
  if (!qId.count(x)) qId[x] = qId.size();
  return qId[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i];
    queries[i] = getId(queries[i]);
  }
    
  vector < pair <int,int> > gcdList;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < int(gcdList.size()); j++)
      gcdList[j].first = __gcd(gcdList[j].first, a[i]);
    gcdList.push_back(make_pair(a[i], i));
    
    sort(gcdList.begin(), gcdList.end());
    
    int newSize = 1;
    for (int j = 1; j < int(gcdList.size()); j++)
      if (gcdList[j].first != gcdList[newSize - 1].first)
        gcdList[newSize++] = gcdList[j];
        
    gcdList.resize(newSize);
        
    for (int j = 0; j < int(gcdList.size()); j++)
      if (qId.count(gcdList[j].first))
      {
        int length = i + 1;
        if (j + 1 < gcdList.size()) length = gcdList[j + 1].second;
        length -= gcdList[j].second;
        ans[qId[gcdList[j].first]] += length;
      }
  }
  
  for (int i = 0; i < q; i++) 
    cout << ans[queries[i]] << '\n';
}