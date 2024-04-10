#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 3e5+5;

int n, m;
ll a[ms], b[ms];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> b[i];
  int i = 0, j = 0;
  int ans = 0;
  ll sumA = a[0], sumB = b[0];
  while(i < n || j < m) {
    if(sumA == sumB) {
      ans++;
      sumA = a[++i];
      sumB = b[++j];
    } else if(sumA < sumB) {
      sumA += a[++i];
    } else {
      sumB += b[++j];
    }
  }
  while(i < n) {
    sumA += a[++i];

  }
  while(j < m) {
    sumB += b[++j];
  }
  if(sumA != sumB) {
    cout << -1 << endl;
  } else if(sumA != 0) {
    cout << ans + 1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}