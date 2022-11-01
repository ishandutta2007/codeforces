#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector <int> ids(8, 0);
  for (int i = 0; i < n; i++) { //  
    if (y[ids[0]] > y[i])
      continue;
    if (y[ids[0]] < y[i]) {
      ids[0] = i;
      continue;
    }
    if (x[ids[0]] > x[i])
      ids[0] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (y[ids[1]] > y[i])
      continue;
    if (y[ids[1]] < y[i]) {
      ids[1] = i;
      continue;
    }
    if (x[ids[1]] < x[i])
      ids[1] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (x[ids[2]] > x[i])
      continue;
    if (x[ids[2]] < x[i]) {
      ids[2] = i;
      continue;
    }
    if (y[ids[2]] < y[i])
      ids[2] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (x[ids[3]] > x[i])
      continue;
    if (x[ids[3]] < x[i]) {
      ids[3] = i;
      continue;
    }
    if (y[ids[3]] > y[i])
      ids[3] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (y[ids[4]] < y[i])
      continue;
    if (y[ids[4]] > y[i]) {
      ids[4] = i;
      continue;
    }
    if (x[ids[4]] < x[i])
      ids[4] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (y[ids[5]] < y[i])
      continue;
    if (y[ids[5]] > y[i]) {
      ids[5] = i;
      continue;
    }
    if (x[ids[5]] > x[i])
      ids[5] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (x[ids[6]] < x[i])
      continue;
    if (x[ids[6]] > x[i]) {
      ids[6] = i;
      continue;
    }
    if (y[ids[6]] > y[i])
      ids[6] = i;
  }
  for (int i = 0; i < n; i++) { //  
    if (x[ids[7]] < x[i])
      continue;
    if (x[ids[7]] > x[i]) {
      ids[7] = i;
      continue;
    }
    if (y[ids[7]] < y[i])
      ids[7] = i;
  }
  int ans3 = 0, ans4 = 0;
  vector <int> X(8), Y(8);
  for (int i = 0; i < 8; i++) {
    X[i] = x[ids[i]];
    Y[i] = y[ids[i]];
  }
  for (int a = 0; a <= 7; a++)
    for (int b = a; b <= 7; b++)
      for (int c = b; c <= 7; c++)
        for (int d = c; d <= 7; d++) {
          int distx = abs(X[a] - X[b]) + abs(X[b] - X[c]) + abs(X[c] - X[d]) + abs(X[d] - X[a]);
          int disty = abs(Y[a] - Y[b]) + abs(Y[b] - Y[c]) + abs(Y[c] - Y[d]) + abs(Y[d] - Y[a]);
          int dist = distx + disty;
          if (a == b || a == c || a == d || b == c || b == d || c == d)
            ans3 = max(ans3, dist);
          ans4 = max(ans4, dist);
        }
  for (int a = 0; a <= 7; a++)
    for (int b = a; b <= 7; b++)
      for (int c = 0; c < n; c++) {
        int distx = abs(X[a] - X[b]) + abs(X[b] - x[c]) + abs(x[c] - X[a]);
        int disty = abs(Y[a] - Y[b]) + abs(Y[b] - y[c]) + abs(y[c] - Y[a]);
        int dist = distx + disty;
        ans3 = max(ans3, dist);
      }
  cout << ans3 << ' ';
  for (int i = 4; i <= n; i++)
    cout << ans4 << ' ';
  return 0;
}