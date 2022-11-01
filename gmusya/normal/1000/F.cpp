#pragma GCC optimize ("Ofast")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

const int K = 800;

int all = 0;

vi a;
vi cnt(500'001);
vi bl(626);

void add(int x) {
  cnt[x]++;
  if (cnt[x] == 1) {
    all++;
    bl[x / K]++;
  } else if (cnt[x] == 2) {
    all--;
    bl[x / K]--;
  }
}

void erase(int x) {
  if (cnt[x] == 2) {
    all++;
    bl[x / K]++;
  } else if (cnt[x] == 1) {
    all--;
    bl[x / K]--;
  }
  cnt[x]--;
}

void mo(int oldl, int oldr, int newl, int newr) {
  while (newl < oldl)
    add(a[newl++]);
  while (newr > oldr)
    add(a[newr--]);
  while (oldl < newl)
    erase(a[oldl++]);
  while (oldr > newr)
    erase(a[oldr--]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int q;
  cin >> q;
  vi l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  int oldl = 1, oldr = 0;
  vi p(q);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    int bla = l[i] / K, blb = l[j] / K;
    if (bla != blb)
      return bla < blb;
    if (bla & 1)
      return r[i] > r[j];
    return r[i] < r[j];
  });
  vi ans(q);
  for (int id : p) {
    int newl = l[id], newr = r[id];
    mo(oldl, oldr, newl, newr);
    oldl = newl, oldr = newr;
    if (!all) {
      ans[id] = 0;
    } else {
      for (int i = 0; i <= 625; i++) {
        if (bl[i]) {
          for (int j = i * K; 1; j++)
            if (cnt[j] == 1) {
              ans[id] = j;
              break;
            }
          break;
        }
      }
    }
  }
  for (auto &now : ans)
    cout << now << '\n';
  return 0;
}