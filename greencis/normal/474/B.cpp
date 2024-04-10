#include <bits/stdc++.h>
using namespace std;

int n,a,sum,m,x;
set< pair<int,int> > s;

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x, s.insert(make_pair(sum+=x, i+1));
  cin >> m;
  while (m--) {
    cin >> x;
    cout << (s.lower_bound(make_pair(x,0))->second) << "\n";
  }
}