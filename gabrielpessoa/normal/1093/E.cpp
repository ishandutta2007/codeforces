// Educational Codeforces Round #56
// E - Intersection of Permutations
// https://codeforces.com/contest/1093/problem/E

#include <bits/stdc++.h>
using namespace std;

const int gsz = 1880, ms = 2e5+5;

int val[ms];
int arr[ms];
vector<int> blocks[ms];

void change(int b, int x, int y) {
  for(int i = 0; i < blocks[b].size(); i++) {
    if(blocks[b][i] == x) {
      blocks[b][i] = y;
      while(i > 0 && blocks[b][i] < blocks[b][i-1]) {
        swap(blocks[b][i], blocks[b][i-1]);
        i--;
      }
      while(i < blocks[b].size() - 1 && blocks[b][i] > blocks[b][i+1]) {
        swap(blocks[b][i], blocks[b][i+1]);
        i++;
      }
      return;
    }
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    val[x] = i;
  }
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = val[x];
    blocks[i/gsz].emplace_back(arr[i]);
  }
  for(int i = 0; i <= n/gsz; i++) {
    sort(blocks[i].begin(), blocks[i].end());
  }
  for(int q = 0; q < m; q++) {
    int type;
    cin >> type;
    if(type == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      la--; ra--; lb--; rb--;
      int ans = 0;
      for(int i = lb; i <= rb; i++) {
        if(i % gsz == 0 && i + gsz - 1 <= rb) {
          int gIdx = i / gsz;
          ans += upper_bound(blocks[gIdx].begin(), blocks[gIdx].end(), ra) - lower_bound(blocks[gIdx].begin(), blocks[gIdx].end(), la);
          i += gsz-1;
        } else {
          ans += arr[i] >= la && arr[i] <= ra;
        }
      }
      cout << ans << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      x--; y--;
      if(x/gsz != y/gsz) {
        change(x/gsz, arr[x], arr[y]);
        change(y/gsz, arr[y], arr[x]);
      } 
      swap(arr[x], arr[y]);
    }
  }
}