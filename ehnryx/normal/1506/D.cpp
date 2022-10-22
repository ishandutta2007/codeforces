#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  int n;
  cin >> n;
  map<int,int> cnt;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  vector<int> a;
  transform(begin(cnt), end(cnt), back_inserter(a), [](const auto& it) {
    return it.second;
  });
  auto it = max_element(begin(a), end(a));
  cout << (*it > n - *it ? *it - (n - *it) : n % 2) << nl;

  return 0;
}