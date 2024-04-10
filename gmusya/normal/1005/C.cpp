#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map <int, int> cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <int> p = {1};
  while (p.back() <= 1'000'000'000)
    p.push_back(p.back() * 2);
  for (int x : a)
    cnt[x]++;
  set <int> s;
  for (auto [val, cn] : cnt) {
    for (int x : p) {
      int toadd = x - val;
      if (cnt.find(toadd) == cnt.end() || (toadd == val && cn == 1))
        continue;
      s.insert(val);
    }
  }
  int answer = 0;
  for (int x : s)
    answer += cnt[x];
  cout << n - answer;
  return 0;
}