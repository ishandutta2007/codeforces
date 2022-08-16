#include <bits/stdc++.h>

using namespace std;


int N, M, Q;
int T[100005], I[100005], J[100005];
char buff[64];
vector< int > graph[100005];
bool reef[1005][1005];
int ans[100005];
int sz;


void Solve(int idx)
{
  bool update = false;
  switch(T[idx]) {
    case 1:
      if(!reef[I[idx]][J[idx]]) {
        reef[I[idx]][J[idx]] = true;
        update = true;
        ++sz;
      }
      break;
    case 2:
      if(reef[I[idx]][J[idx]]) {
        reef[I[idx]][J[idx]] = false;
        update = true;
        --sz;
      }
      break;
    case 3:
      for(int i = 1; i <= M; i++) {
        if(reef[I[idx]][i]) --sz;
        else ++sz;
        reef[I[idx]][i] ^= 1;
      }
      break;
    default:
      break;
  }
  ans[idx] = sz;
  for(int to : graph[idx]) {
    Solve(to);
  }
  switch(T[idx]) {
    case 1:
      if(update) {
        reef[I[idx]][J[idx]] = false;
        --sz;
      }
      break;
    case 2:
      if(update) {
        reef[I[idx]][J[idx]] = true;
        ++sz;
      }
      break;
    case 3:
      for(int i = 1; i <= M; i++) {
        if(reef[I[idx]][i]) --sz;
        else ++sz;
        reef[I[idx]][i] ^= 1;
      }
      break;
    default:
      break;
  }
}

int main()
{
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d %d %d", &N, &M, &Q);

  T[0] = 114514;

  for(int i = 1; i <= Q; i++) {
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d %d %d", &T[i], &I[i], &J[i]);
    if(T[i] == 4) {
      graph[I[i]].push_back(i);
    } else {
      graph[i - 1].push_back(i);
    }
  }

  Solve(0);

  for(int i = 1; i <= Q; i++) {
    printf("%d\n", ans[i]);
  }
}