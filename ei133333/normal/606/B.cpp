#include<bits/stdc++.h>
using namespace std;
int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};
const string T = "LRUD";
typedef pair< int, int > Pi;

int main()
{
  int x, y, sx, sy;
  cin >> x >> y >> sx >> sy;
  swap(x, y);
  swap(sx, sy);

  string S;
  cin >> S;
  int ret = x * y;
  set< Pi > used;
  used.insert(Pi(sx, sy));
  cout << "1 ";
  ret--;
  for(int i = 0; i < S.size(); i++) {
    int pos = T.find(S[i]);
    int nx = dx[pos] + sx, ny = dy[pos] + sy;
    if(1 <= nx && 1 <= ny && nx <= x && ny <= y) {
      sx = nx, sy = ny;
    }
    bool F = (used.find(Pi(sx, sy)) != used.end());
    if(i + 1 != S.size()) {
      if(F) cout << "0 ";
      else cout << "1 ";
    } else {
      cout << ret << endl;
    }
    ret -= 1 - F;
    used.insert(Pi(sx, sy));
  }
}