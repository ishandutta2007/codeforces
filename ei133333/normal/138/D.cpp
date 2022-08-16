#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int uku[41][41][41][41];
char mp[41][41];
map< pair< int, int >, char > mp1, mp2;

int check(int lx, int rx, int ly, int ry) {
  if(lx>rx||ly>ry) return 0;
  if(~uku[lx][rx][ly][ry]) return uku[lx][rx][ly][ry];
  set< int > st;
  for(int i = ly; i <= ry; i++) {
    for(int j = lx; j <= rx; j++) {
      if(mp[i][j] == '*') continue;
      if(mp[i][j] == 'L') {
        st.emplace(check(lx, j - 1, ly, ry) ^
                   check(j + 1, rx, ly, ry));
      } else if(mp[i][j] == 'R') {
        st.emplace(check(lx, rx, ly, i - 1) ^
                   check(lx, rx, i + 1, ry));
      } else {
        st.emplace(check(lx, j - 1, ly, i - 1) ^
                   check(lx, j - 1, i + 1, ry) ^
                   check(j + 1, rx, ly, i - 1) ^
                   check(j + 1, rx, i + 1, ry));
      }
    }
  }
  int ret = 0;
  while(st.count(ret)) ++ret;
 return uku[lx][rx][ly][ry] = ret;
}


int main() {
  int N, M;
  string S[20];
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    for(int j = 0; j < M; j++) {
      if((i + j) & 1) mp1[{i - j, i + j}] = S[i][j];
      else mp2[{i - j, i + j}] = S[i][j];
    }
  }


  fill_n(*mp, 41 * 41, '*');
  memset(uku, -1, sizeof(uku));
  for(auto &p : mp1) mp[p.first.first + 20][p.first.second] = p.second;
  auto ret1 = check(0, 40, 0, 40);

  fill_n(*mp, 41 * 41, '*');
  memset(uku, -1, sizeof(uku));
  for(auto &p : mp2) mp[p.first.first + 20][p.first.second] = p.second;
  auto ret2 = check(0, 40, 0, 40);

  if((ret1 ^ ret2) == 0) puts("LOSE");
  else puts("WIN");
}