#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e6+5;

int arr[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  vector<int> poss;
  int x = sum;
  for(int i = 2; i * i <= x; i++) {
    if(x % i == 0) {
      poss.emplace_back(i);
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) poss.emplace_back(x);
  int ans = inf;
  for(int k : poss) {
    int cur = 0;
    int temp = 0;
    // cout << k << endl;
    for(int i = 0; i < n; i++) {
      cur = (cur + arr[i]) % k;
      temp += min(cur, k - cur);
      // cout << "tenho agr " << cur << ' ' << temp << endl;
    }
    ans = min(ans, temp);
  }
  if(ans == inf) {
    ans = -1;
  }
  cout << ans << '\n';
}