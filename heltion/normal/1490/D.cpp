#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    vector<int> v(n), d(n);
    for(int &x : v) cin >> x;
    function<void(int, int, int)> DFS = [&](int L, int R, int D){
      int M = max_element(v.begin() + L, v.begin() + R + 1) - v.begin();
      d[M] = D;
      if(L < M) DFS(L, M - 1, D + 1);
      if(R > M) DFS(M + 1, R, D + 1);
    };
    DFS(0, n - 1, 0);
    for(int x : d) cout << x << " ";
    cout << "\n";
  }
  return 0;
}