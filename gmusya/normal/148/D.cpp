#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

#define fsp(x) fixed << setprecision(x)
#define fi first
#define se second

using namespace std;

typedef long double ld;

map <pair <pair <int, int>, bool>, ld> m;

ld solve(pair <pair <int, int>, bool> st) {
  if (st.fi.fi < 0 || st.fi.se < 0)
    return 1;
  if (!(st.fi.fi))
    return (ld) st.se;
  if (m.find(st) != m.end())
    return m[st];
  ld res = 0;
  ld w = st.fi.fi, b = st.fi.se;
  res += w / (w + b);
  if (st.fi.fi + st.fi.se == 1)
    return m[st] = res;
  if (st.se) {
    res += b / (w + b) * w / (w + b - 1) * (1 - solve({{st.fi.fi - 1, st.fi.se - 1}, !st.se}));
    res += b / (w + b) * (b - 1) / (w + b - 1) * (1 - solve({{st.fi.fi, st.fi.se - 2}, !st.se}));
  } else {
    res += b / (w + b) * (1 - solve({{st.fi.fi, st.fi.se - 1}, !st.se}));
  }
  return m[st] = res;
}

int main() {
  int w, b;
  cin >> w >> b;
  cout << fsp(15) << solve({{w, b}, false});
  return 0;
}