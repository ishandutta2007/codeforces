#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

const int ms = 1e6+5;

int n, x;
vector<ii> arr[ms];
set<int> s;
int z = 0;


main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> x;
  int big = 0;
  int hiMinimum = 1;
  int loMaximum = x;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a < big) {
      arr[a].emplace_back(*s.upper_bound(a), big);
      hiMinimum = max(a, hiMinimum);
    } else big = a;
    s.insert(a);
  }
  int ans = 0;
  for(int i = 1; i <= loMaximum; i++) {
    hiMinimum = max(hiMinimum, i);
    ans += (x - hiMinimum + 1);
    for(auto p : arr[i]) {
      loMaximum = min(loMaximum, p.first);
      hiMinimum = max(hiMinimum, p.second);
    }
  }
  cout << ans << endl;
}