#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
struct UnionFindTree
{
  vector< int > data;
  UnionFindTree(int sz)
  {
    data.assign(sz, -1);
  }
  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }
  int size(int k)
  {
    return(-data[find(k)]);
  }
  void unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};
#define int long long
int N, M;
int64 K;
int A[1000][1000];
const int vy[] = {0, 1, 0, -1}, vx[] = {1, 0, -1, 0};

inline int get(int y, int x)
{
  return(y * M + x);
}

signed main()
{

  scanf("%I64d %I64d %I64d", &N, &M, &K);
  UnionFindTree uftree(N * M);
  vector< pair< int64, pair< int, int > > > pts(N * M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%I64d", &A[i][j]);
      pts[get(i, j)] = {A[i][j], {i, j}};
    }
  }
  sort(pts.rbegin(), pts.rend());
  for(auto e : pts) {
    int i = e.second.first, j = e.second.second;
    for(int k = 0; k < 4; k++) {
      int ni = i + vy[k], nj = j + vx[k];
      if(ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
      if(A[i][j] <= A[ni][nj]) uftree.unite(get(i, j), get(ni, nj));
    }

    if(K % e.first == 0) {
      int64 mul = K / e.first;
      if(uftree.size(get(i, j)) >= mul) {
        printf("YES\n");

        queue< pair< int, int > > que;
        int load[1000][1000] = {{}};
        que.push({i, j});
        while(!que.empty()) {
          auto p = que.front(); que.pop();
          if(load[p.first][p.second] > 0) continue;
          if(mul == 0) break;
          --mul;
          load[p.first][p.second] = e.first;
          for(int k = 0; k < 4; k++) {
            int ni = p.first + vy[k], nj = p.second + vx[k];
            if(ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
            if(A[i][j] <= A[ni][nj]) {
              if(load[ni][nj] > 0) continue;
              que.push({ni, nj});
            }
          }
        }
        for(int a = 0; a < N; a++) {
          bool first = false;
          for(int b = 0; b < M; b++) {
            if(first++) putchar(' ');
            printf("%I64d", load[a][b]);
          }
          puts("");
        }
        exit(0);
      }
    }
  }
  puts("NO");
}