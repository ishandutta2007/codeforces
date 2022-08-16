#include<bits/stdc++.h>

using namespace std;
const int INF = 1 << 30;

struct edge
{
  int to, num;

};

int dp[100][100][26][2];
int N, M;
vector< edge > G[100];

bool iswin(int latte, int malta, int num, bool which)
{
  if(~dp[latte][malta][num][which]) return (dp[latte][malta][num][which]);
  bool beet = false;
  for(auto &e : G[which?malta:latte]) {
    if(e.num < num) continue;
    if(which) beet |= !iswin(latte, e.to, e.num, 1 ^ which);
    else beet |= !iswin(e.to, malta, e.num, 1 ^ which);
  }
  return (dp[latte][malta][num][which] = beet);
}

int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int x, y;
    char z;
    cin >> x >> y >> z;
    z -= 'a';
    --x, --y;
    G[x].push_back((edge) {y, z});
  }

  memset(dp, -1, sizeof(dp));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(iswin(i, j, 0, false)) cout << "A";
      else cout << "B";
    }
    cout << endl;
  }
}