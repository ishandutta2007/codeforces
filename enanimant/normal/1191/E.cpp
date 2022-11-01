#include <bits/stdc++.h>

using namespace std;


int n, k;
int v[2][2]; // v[i]: leftmost and rightmost cards in state i
int cur[2];
bool draw;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> k;
  v[0][0] = v[1][0] = n;
  v[0][1] = v[1][1] = -1;
  draw = false;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    int a = c - '0';
    v[a][0] = min(v[a][0], i);
    v[a][1] = max(v[a][1], i);
    cur[a]++;
    if (cur[a] == k) {
      draw = true;
    }
    cur[a ^ 1] = 0;
  }
  for (int i = 0; i <= 1; i++) {
    if (v[i][1] == -1 || v[i][1] - v[i][0] + 1 <= k) {
      cout << "tokitsukaze\n"; // wins in one move
      return 0;
    }
  }
  for (int i = 0; i <= 1; i++) {
    if (v[i][1] - v[i][0] + 1 >= k + 2 || (v[i][0] >= k && v[i][1] < n - k)) {
      draw = true; // first player can force a draw
    }
  }
  cout << (draw ? "once again" : "quailty") << '\n';


  return 0;
}