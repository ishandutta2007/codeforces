/*
 * author:  ADMathNoob
 * created: 09/12/21 10:35:18
 * problem: https://codeforces.com/contest/1566/problem/D2
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
void MakeUnique(vector<T>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

template <typename T>
vector<int> Compressed(const vector<T>& a, const vector<T>& v) {
  int n = (int) a.size();
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = (int) (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
  }
  return res;
}

template <typename T>
vector<int> Compressed(vector<T>& a) {
  vector<T> v = a;
  MakeUnique(v);
  return Compressed(a, v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i];
    }
    auto as = a;
    MakeUnique(as);
    const int A = (int) as.size();
    a = Compressed(a, as);
    vector<int> cnt(A, 0);
    vector<vector<int>> occ(A);
    for (int i = 0; i < n * m; i++) {
      cnt[a[i]] += 1;
      occ[a[i]].push_back(i);
    }
    vector<int> pref(A + 1);
    for (int x = 0; x < A; x++) {
      pref[x + 1] = pref[x] + cnt[x];
    }
    vector<vector<int>> cur(n, vector<int>(m, n * m));
    int ans = 0;
    for (int x = 0; x < A; x++) {
      int from = pref[x];
      int to = pref[x + 1] - 1;
      int first = m - (from % m);
      int last = (to % m) + 1;
      int r1 = from / m;
      int r2 = to / m;
      if (r1 == r2) {
        for (int z = 0; z < cnt[x]; z++) {
          int id = occ[x][cnt[x] - 1 - z];
          int col = (from % m) + z;
          for (int j = 0; j < col; j++) {
            if (cur[r1][j] < id) {
              ++ans;
            }
          }
          cur[r1][col] = id;
        }
      } else {
        for (int z = 0; z < first; z++) {
          int id = occ[x][first - 1 - z];
          int col = (from % m) + z;
          for (int j = 0; j < col; j++) {
            if (cur[r1][j] < id) {
              ++ans;
            }
          }
          cur[r1][col] = id;
        }
        for (int z = 0; z < last; z++) {
          int id = occ[x][cnt[x] - 1 - z];
          int col = z;
          for (int j = 0; j < col; j++) {
            if (cur[r2][j] < id) {
              ++ans;
            }
          }
          cur[r2][col] = id;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}