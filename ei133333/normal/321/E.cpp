#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

char in[1<<26]; // sizeof in varied in problem
char const*o;

void init_in()
{
  o = in;
  in[ fread(in,1,sizeof(in)-4,stdin)]=0;//set 0 at the end of buffer.
}

int readInt(){
  unsigned u = 0, s = 0;

  while(*o && *o <= 32)++o; //skip whitespaces...

  if (*o == '-')s = ~s, ++o; else if (*o == '+')++o; // skip sign

  while(*o>='0' && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');  // u * 10 = u * 8 + u * 2 :)

  return static_cast<int>( (u^s) + !!s) ;
}

template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D() {}


  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

  inline void add(int x, int y, int z) {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      for(int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  inline T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};


int main() {
  init_in();
  int N = readInt();
  int K = readInt();
  CumulativeSum2D< int > sum(N, N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int x = readInt();
      sum.add(i, j, x);
    }
  }
  sum.build();
  vector< int > dp(N + 1, INF);
  dp[0] = 0;
  for(int i = 1; i <= K; i++) {
    vector< int > dp2(N + 1, INF);
    queue< pair< pair< int, int >, pair< int, int > > > que;
    que.emplace(make_pair(0, N + 1), make_pair(0, N + 1));
    while(que.size()) {
      int left = que.front().first.first;
      int right = que.front().first.second;
      int latte = que.front().second.first;
      int malta = que.front().second.second;
      que.pop();
      if(left >= right) continue;
      int mid = (left + right) >> 1;
      int best = -1;
      for(int k = latte; k < min(mid, malta); k++) {
        int cost = dp[k] + sum.query(k, k, mid, mid);
        if(cost < dp2[mid]) {
          dp2[mid] = cost;
          best = k;
        }
      }
      que.emplace(make_pair(left, mid), make_pair(latte, best + 1));
      que.emplace(make_pair(mid + 1, right), make_pair(max(0, best), malta));
    }
    dp.swap(dp2);
  }
  printf("%d\n", dp.back() / 2);
}