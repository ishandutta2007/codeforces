#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;
int loc[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a; cin >> a; loc[a] = i;
  }
  int cur = 0;
  for (int i = 1; i <= N; i++) {
    int b; cin >> b;
    int nxt = max(cur, loc[b]);
    cout << nxt - cur << '\n';
    cur = nxt;
  }
}