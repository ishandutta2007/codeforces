// author: erray
#include<bits/stdc++.h>
 
using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  shuffle(ord.begin(), ord.end(), rng);
  auto ask = [&](int x, int y) {
    cout << "? " << ord[x] + 1 << ' ' << ord[y] + 1 << endl;
    int res;
    cin >> res;
    return res;
  };
  int a = 0, b = 1, bef = ask(0, 1);
  int cnt = 0;
  for (int i = 2; i < n; ++i) {
    int cur = ask(i, b);
    if (cur == bef) {
      ++cnt;
      b = i;
      bef = ask(i, a);
    } else if (cur < bef) {
      a = i;
      swap(cur, bef);
    } 
  }
  assert(cnt <= 4269 - 4092);
  int finAsk = -1;
  do {
   ++finAsk;
   while (a == finAsk || b == finAsk) {
     ++finAsk;
    }
  } while (ask(a, finAsk) == ask(b, finAsk));
  if (ask(a, finAsk) > ask(b, finAsk)) swap(a, b);
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (i == a) continue;
    ans[ord[i]] = ask(i, a); 
  }
  cout << "! ";
  for (auto el : ans) cout << el << ' ';
  cout << endl;
}