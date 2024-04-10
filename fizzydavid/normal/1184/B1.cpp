#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s, b;
  cin >> s >> b;
  vector <int> x;
  for (int i = 0; i < s; i++) {
    int a;
    cin >> a;
    x.push_back(a);
  }
  vector <pair <int, int> > ok;
  for (int i = 0; i < b; i++) {
    int d, g;
    cin >> d >> g;
    ok.push_back({d, g});
  }
  sort(ok.begin(), ok.end());
  vector <int> pref(ok.size());
  for (int i = 0; i < (int)ok.size(); i++) {
    pref[i] = ok[i].second;
    if (i) pref[i] += pref[i - 1];
  }
  int inf = (int) (1e9) + 7;
  for (int i = 0; i < s; i++) {
    int a = x[i];
    int ind = upper_bound(ok.begin(), ok.end(), make_pair(a, inf)) - ok.begin() - 1;
    if (ind >= 0) {
      cout << pref[ind] << ' ';
    } else {
      cout << 0 << ' ';
    }
  }
  cout << '\n';
}