#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[ms];
vector<int> g[ms];
vector<int> poss[ms];
int k[ms];
int sum[ms];
pair<double, int> vec[ms];
double eps = 1e-9;
int n, m;

void ans() {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < k[i]; j++) {
      cout << poss[i][j];
    }
  }
  cout << '\n';
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  reverse(a, a+n);
  for(int i = 0; i < m; i++) {
    cin >> k[i];
    g[i].resize(k[i]);
    poss[i].resize(k[i]);
    sum[i] = 0;
    for(int j = 0; j < k[i]; j++) {
      cin >> g[i][j];
      poss[i][j] = 0;
      sum[i] += g[i][j];
    }
    vec[i] = {1.0 * sum[i] / k[i] - eps, i};
  }
  sort(vec, vec+m);
  reverse(vec, vec+m);
  bool startPoss = true;
  bool everPoss = true;
  int unicoProibido = -1;
  int biggerIdx = inf;
  int smallerIdx = -1;
  for(int i = 0; i < m; i++) {
    // cout << vec[i].first << " " << a[i] << endl;
    if(vec[i].first > a[i]) {
      startPoss = false;
      if (i == 0 || vec[i].first > a[i-1]) {
        if(unicoProibido == -1) {
          unicoProibido = i;
          smallerIdx = i;
        } else {
          everPoss = false;
        }
      } else {
        biggerIdx = min(biggerIdx, i); // vec[i].first
        smallerIdx = i; // a[i]
      }
    }
  }
  if (!everPoss) {
    // cout << "never poss " << endl;
    ans();
    return;
  }
  if(unicoProibido != -1) {
    if (unicoProibido <= biggerIdx) {
      // nice
      int idx = vec[unicoProibido].second;
      for(int j = 0; j < k[idx]; j++) {
        int newSum = sum[idx] - g[idx][j];
        double newAvg = 1.0 * newSum / (k[idx]-1) - eps;
        if(newAvg < a[smallerIdx]) {
          poss[idx][j] = 1;
        }
      }
      ans();
      return;
    } else {
      ans();
      return;
    }
  } else if(!startPoss) {
    // cout << biggerIdx << " " << a[smallerIdx] << endl;
    for(int i = 0; i <= biggerIdx; i++) {
      int idx = vec[i].second;
      for(int j = 0; j < k[idx]; j++) {
        int newSum = sum[idx] - g[idx][j];
        double newAvg = 1.0 * newSum / (k[idx]-1) - eps;
        if(newAvg < a[smallerIdx]) {
          poss[idx][j] = 1;
        }
      }
    }
    ans();
    return;
  }
  int cant = 0;
  // cout << a[cant] << endl;
  // cout << vec[0].first << endl;
  for(int i = 0; i < m; i++) {
      int idx = vec[i].second;
      for(int j = 0; j < k[idx]; j++) {
        int newSum = sum[idx] - g[idx][j];
        double newAvg = 1.0 * newSum / (k[idx]-1) - eps;
        // cout << newAvg << " ";
        poss[idx][j] = 1;
        if(newAvg > a[cant]) {
          poss[idx][j] = 0;
        }
      }
      if(i != m-1 && vec[i].first > a[i+1]) {
        cant = i+1;
      }
  }
  ans();
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // #ifdef ONLINE_JUDGE
  //   freopen("grid.in", "r", stdin);
  //   freopen("grid.out", "w", stdout);
  // #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}