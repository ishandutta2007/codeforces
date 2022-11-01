#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> t;

int n;

void upd(int pos, int val) {
  for (int x = pos; x < n; x |= x + 1)
    t[x] += val;
}

int get(int pos) {
  int res = 0;
  for (int x = pos; x != -1; x = (x & (x + 1)) - 1)
    res += t[x];
  return res;
}

int main() {
  cin >> n;
  vector <char> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  vector <vector <int>> cnt(26);
  vector <int> it(26);
  for (int i = 0; i < n; i++)
    cnt[c[i] - 'a'].push_back(i);
  vector <char> r = c;
  reverse(r.begin(), r.end());
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = cnt[r[i] - 'a'][it[r[i] - 'a']++];
  t.resize(n);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += get(a[i]);
    upd(a[i], 1);
  }
  cout << ans;
  return 0;
}