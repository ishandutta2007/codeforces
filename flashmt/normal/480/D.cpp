#include <bits/stdc++.h>
using namespace std;

struct Parcel
{
  int in, out, w, s, v;
  
  bool operator < (Parcel u) const
  {
    if (out - in != u.out - u.in) return out - in < u.out - u.in;
    return in < u.in;
  }
};

Parcel p[555];
int n, S, f[555][1010], best[2020];
vector <int> endAt[2020];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n >> S;
  p[0].in = p[0].w = p[0].v = 0;
  p[0].out = n * 2;
  p[0].s = S;
  
  for (int i = 1; i <= n; i++)
    cin >> p[i].in >> p[i].out >> p[i].w >> p[i].s >> p[i].v;
    
  sort(p, p + n + 1);
  for (int i = 0; i <= n; i++) endAt[p[i].out].push_back(i);
  
  for (int i = 0; i <= n; i++)
    for (int j = p[i].w; j <= S; j++)
    {
      best[p[i].in] = 0;
      for (int k = p[i].in; k <= p[i].out; k++)
      {
        for (int q = 0; q < int(endAt[k].size()); q++)
        {
          int id = endAt[k][q];
          if (id == i) continue;
          if (p[id].in >= p[i].in) best[k] = max(best[k], best[p[id].in] + f[id][min(p[i].s, j - p[i].w)]);
        }
        best[k + 1] = best[k];
      }
      
      f[i][j] = best[p[i].out] + p[i].v;
    }
    
  cout << f[n][S] << endl;
}