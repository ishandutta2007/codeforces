#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct edge
{
  int to, cost;
};

vector< edge > graph[5003];
int dp[5003][5003], rev[5003][5003];

vector< int > order;
bool used[5003];

void dfs(int idx)
{
  if(used[idx]++) return;
  for(auto& e : graph[idx]) dfs(e.to);
  order.push_back(idx);
}

int main()
{
  int N, M, T;

  cin >> N >> M >> T;
  while(M--) {
    int A, B, C;
    cin >> A >> B >> C;
    graph[--B].push_back((edge) {--A, C});
  }

  for(int i = 0; i < N; i++) dfs(i);
  reverse(begin(order), end(order));

  fill_n(*dp, 5003 * 5003, INF);
  dp[N - 1][0] = 0;

  for(int _ = 0; _ < N; _++) {
    int i = order[_];
    for(int j = 0; j < N; j++) {
      for(edge& e : graph[i]) {
        if(dp[e.to][j + 1] > dp[i][j] + e.cost) {
          dp[e.to][j + 1] = dp[i][j] + e.cost;
          rev[e.to][j + 1] = i;
        }
      }
    }
  }

  int curr = N;
  while(dp[0][curr] > T) --curr;

  cout << curr + 1 << endl;

  vector< int > now;
  int pos = 0;
  for(int i = curr; i >= 0; i--) {
    cout << pos + 1 << " ";
    pos = rev[pos][i];
  }
}