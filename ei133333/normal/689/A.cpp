#include<bits/stdc++.h>
using namespace std;
const int digit[4][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
  {-1, 0, -1}
};

pair< int, int > find(int d)
{
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      if(digit[i][j] == d) return(make_pair(i, j));
    }
  }
}

bool able(int y, int x, int idx, vector< pair< int, int > >& ret)
{
  if(idx + 1 == ret.size()) return(true);
  int ny = y + ret[idx + 1].first - ret[idx].first;
  int nx = x + ret[idx + 1].second - ret[idx].second;
  if(ny < 0 || nx < 0 || ny >= 4 || nx >= 3) return(false);
  if(digit[ny][nx] == -1) return(false);
  return(able(ny, nx, idx + 1, ret));
}
int main()
{
  int N;
  string S;
  cin >> N;
  cin >> S;
  for(char& c : S) c -= '0';

  vector< pair< int, int > > res;
  for(char& c: S) res.push_back(find(c));
  int ret = 0;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      if(digit[i][j] == -1) continue;
      ret += able(i, j, 0, res);
    }
  }
  puts(ret == 1 ? "YES" : "NO");
}