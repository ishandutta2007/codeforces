#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector< pair< pair< int, int >, int > > d(N);
    for(int i = 0; i < N; i++) {
      cin >> d[i].first.first >> d[i].first.second;
      d[i].second = i;
    }
    sort(begin(d), end(d));
    vector< int > ans(N, -1);
    int uku = -1;
    for(int i = 1; i < d.size(); i++) {
      uku = max(uku, d[i - 1].first.second);
      if(uku < d[i].first.first) {
        for(int j = 0; j < i; j++) ans[d[j].second] = 1;
        for(int j = i; j < N; j++) ans[d[j].second] = 2;
        break;
      }
    }
    if(ans[0] == -1) {
      cout << -1 << endl;
    } else {
      for(auto &p : ans) cout << p << " ";
      cout << endl;
    }
  }

}