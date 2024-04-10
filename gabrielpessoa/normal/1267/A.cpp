#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 4e5+5;

vector<ii> eve;
int t[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  set<ii> s;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b >> t[i];
    b -= t[i];
    eve.emplace_back(a, i);
    eve.emplace_back(b+1, -i);
  }
  sort(eve.begin(), eve.end());
  int curEnd = eve[0].first;
  int ans = 0;
  for(int i = 0; i < eve.size() - 1; i++) {
    if(eve[i].second > 0) s.emplace(t[eve[i].second], eve[i].second);
    else s.erase(ii(t[-eve[i].second], -eve[i].second));
    int cur = eve[i].first;
    if(!s.empty()) curEnd = min(curEnd, eve[i].first + s.begin()->first);
    else curEnd = max(curEnd, eve[i+1].first);
    if(!s.empty()) {
      int dur = s.begin()->first;
      int qnt = (eve[i+1].first - curEnd + dur - 1) / dur;
      // cout << ans << ' ' << qnt << ' ' << dur << ' ' << curEnd << ' ' << eve[i+1].first << endl;
      curEnd += qnt * dur;
      ans += qnt;
    }
  }
  cout << ans << '\n';
}