#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void end(int i) {
  cout << i << endl;
  exit(0);
}

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) cin >> arr[i];
    int cur = 1, biggest = 1, lowest = 1;
    for (int i = 0; i < n-1; i++) {
      cur += arr[i];
      biggest = max(biggest, cur);
      lowest = min(lowest, cur);
    }
    if (biggest - lowest != n - 1) end(-1);
    cur = (2 - lowest);
    bool vis[n+1];
    memset(vis, 0, sizeof(vis));
    string seq = to_string(cur);
    for (int i = 0; i < n-1; i++) {
      if (vis[cur]) end(-1);
      vis[cur] = 1;
      cur += arr[i];
      seq += " " + to_string(cur);
    }
    if (vis[cur]) end(-1);
    cout << seq << endl;
}