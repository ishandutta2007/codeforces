#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

vi lp, ord;

void init() {
  vi pr;
  lp.resize(3'000'000);
  for (int i = 2; i <= 2'999'999; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i <= 2'999'999; j++)
      lp[pr[j] * i] = i;
  }
  ord.resize(3'000'000);
  for (int i = 0; i < (int) pr.size(); i++)
    ord[pr[i]] = i + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  multiset <int> pr, nonpr;
  for (int i = 0; i < n + n; i++) {
    int x;
    cin >> x;
    if (ord[x])
      pr.insert(x);
    else
      nonpr.insert(x);
  }
  vi ans;
  while (!nonpr.empty()) {
    int x = *nonpr.rbegin();
    ans.push_back(x);
    nonpr.erase(nonpr.find(x));
    if (ord[lp[x]])
      pr.erase(pr.find(lp[x]));
    else
      nonpr.erase(nonpr.find(lp[x]));
  }
  while (!pr.empty()) {
    int p = *pr.rbegin();
    pr.erase(pr.find(p));
    ans.push_back(ord[p]);
    pr.erase(pr.find(ord[p]));
  }
  for (int x : ans)
    cout << x << ' ';
  return 0;
}