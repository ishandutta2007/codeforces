#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map <ll, ll> ans;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans[x - i] += x;
  }
  ll answer = 0;
  for (auto &now : ans)
    answer = max(answer, now.second);
  cout << answer;
  return 0;
}