#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  map< int, long long > row, col;
  map< pair< int, int >, long long > sss;
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    row[x]++;
    col[y]++;
    sss[{x, y}]++;
  }
  long long ret = 0;
  for(auto v : row) {
    ret += 1LL * v.second * (v.second - 1) / 2;
  }
  for(auto v: col) {
    ret += 1LL * v.second * (v.second - 1) / 2;
  }
  for(auto v: sss) {
    ret -= 1LL * v.second * (v.second - 1) / 2;
  }
  cout << ret << endl;
}