#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair< int64, int64 > Pi;

int64 get(Pi& a, Pi& b)
{
  return((a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second));
}

int main()
{
  int64 n;
  Pi a, b;
  Pi p[2000];

  cin >> n >> a.first >> a.second >> b.first >> b.second;
  for(int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  int64 ret = 1LL << 60;
  for(int k = 0; k < 2; k++) {
    for(int i = 0; i < n; i++) {
      int64 dist = get(a, p[i]), res = 0;
      for(int j = 0; j < n; j++) {
        if(get(a, p[j]) > dist) res = max(res, get(b, p[j]));
      }
      ret = min(ret, dist + res);
    }
    swap(a, b);
  }

  cout << ret << endl;
}