#include <iostream>
#include <vector>

using namespace std;

vector <int> s, nxt;

int get(int v) {
  if (nxt[v] == v)
    return v;
  return nxt[v] = get(nxt[v]);
}

void merge(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v)
    return;
  if (v > u)
    swap(u, v);
  nxt[v] = nxt[u];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    s.assign(n, 1e9);
    nxt.assign(n, 0);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    for (int i = 0; i < n; i++)
      nxt[i] = i;
    long long ans = 0;
    int minpos = 0;
    while (true) {
      int pos = minpos;
      bool flag = false;
      while (pos < n && pos + s[pos] < n) {
        if (s[pos] == 1) {
          if (pos)
            merge(pos, pos - 1);
          pos = get(pos) + 1;
          continue;
        }
        if (!flag)
          minpos = pos;
        if (s[pos] != 1)
          flag = true;
        int add = s[pos];
        if (s[pos] > 1)
          s[pos]--;
        if (s[pos] == 1 && pos > 0)
          merge(pos, pos - 1);
        pos += add;
      }
      if (!flag) {
        if (pos >= n)
          break;
        if (pos == n - 1 && s[pos] == 1)
          break;
        if (pos + s[pos] > n) {
          ans += pos + s[pos] - n;
          s[pos] = n - pos;
        } else {
          ans++;
          s[pos]--;
        }
        continue;
      }
      ans++;
      if (pos >= n)
        continue;
      if (s[pos] > 1)
        s[pos]--;
    }
    cout << ans << '\n';
  }
  return 0;
}