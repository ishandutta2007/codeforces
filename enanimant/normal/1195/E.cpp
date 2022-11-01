// July 16, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAX = 3000;

int n, m, a, b;
int gen[MAX * MAX], x, y, z;
int h[MAX][MAX];

template <typename T>
vector<int> sliding_window(const vector<int> &v, int k, const function<bool(T, T)> &f, bool return_indices = false) {
  int n = (int) v.size();
  assert(0 < k && k <= n);
  vector<int> res;
  deque<int> dq;
  function<void(int)> add = [&](int i) {
    while (!dq.empty() && !f(v[dq.back()], v[i])) {
      dq.pop_back();
    }
    dq.push_back(i);
  };
  for (int i = 0; i < k - 1; i++) {
    add(i);
  }
  for (int i = k - 1; i < n; i++) {
    add(i);
    if (dq.front() == i - k) {
      dq.pop_front();
    }
    res.push_back(dq.front());
  }
  if (return_indices) {
    return res;
  }
  for (int i = 0; i < n - k + 1; i++) {
    res[i] = v[res[i]];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m >> a >> b >> gen[0] >> x >> y >> z;
  for (int i = 1; i < n * m; i++) {
    gen[i] = (1LL * gen[i - 1] * x + y) % z;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      h[i][j] = gen[i * m + j];
    }
  }
  vector< vector<int> > swm1(n);
  for (int i = 0; i < n; i++) {
    vector<int> v(h[i], h[i] + m);
    swm1[i] = sliding_window<int>(v, b, [](int x, int y) {
      return x < y;
    });
  }
  long long ans = 0;
  for (int i = 0; i < m - b + 1; i++) {
    vector<int> v(n);
    for (int j = 0; j < n; j++) {
      v[j] = swm1[j][i];
    }
    vector<int> swm = sliding_window<int>(v, a, [](int x, int y) {
      return x < y;
    });
    ans += accumulate(swm.begin(), swm.end(), 0LL);
  }
  cout << ans << '\n';


  return 0;
}