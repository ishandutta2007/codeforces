#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <int, int>> tmp(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp[i].first >> tmp[i].second;
  }
  sort(tmp.begin(), tmp.end());
  vector <int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    a[i] = tmp[i].first;
    c[i] = tmp[i].second;
  }
  vector <int> p(n);
  ll sum = c[0];
  set <pair <int, int>> s;
  s.insert({a[0] + c[0], 0});
  for (int i = 1; i < n; i++) {
    pii res = *s.rbegin();
    s.erase(res);
    int res_id = res.second;
    int diff = max(a[i] - res.first, 0);
    s.insert({max(a[res_id] + c[res_id], a[i]), res_id});
    s.insert({a[i] + c[i], i});
    p[i] = p[p[res_id]];
    p[res_id] = i;
    sum += diff + c[i];
  }
  cout << sum;
  return 0;
}