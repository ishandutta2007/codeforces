#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i=0; i<n; i++) {
      int v;
      cin >> v;
      a.emplace_back(v, i+1);
    }
    sort(begin(a), end(a));

    vector<long long> sum(n);
    for(int i=0; i<n; i++) {
      sum[i] = a[i].first;
      if(i > 0) sum[i] += sum[i-1];
    }

    vector<int> ans(1, a.back().second);
    for(int i=n-2; i>=0; i--) {
      if(a[i+1].first > sum[i]) {
        break;
      }
      ans.push_back(a[i].second);
    }

    sort(begin(ans), end(ans));
    cout << size(ans) << nl;
    for(int it : ans) {
      cout << it << " ";
    }
    cout << nl;
  }

  return 0;
}