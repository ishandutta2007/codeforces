#include<bits/stdc++.h>
using namespace std;

int N, M, A[1000000];
int root[1000000];
vector< int > arr[1000000];
int poyo[1000000];

inline int find(int k)
{
  if(root[k] < 0) return(k);
  return(root[k] = find(root[k]));
}
inline void unite(int x, int y)
{
  x = find(x), y = find(y);
  if(x == y) return;
  if(root[x] > root[y]) swap(x, y);
  root[x] += root[y];
  root[y] = x;
}

int main()
{
  memset(root, -1, sizeof(root));
  
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < M; i++) {
    int U, V;
    scanf("%d %d", &U, &V);
    unite(--U, --V);
  }
  for(int i = 0; i < N; i++) {
    arr[find(i)].emplace_back(A[i]);
  }
  for(int i = 0; i < N; i++) {
    sort(arr[i].rbegin(), arr[i].rend());
  }
  for(int i = 0; i < N; i++) {
    printf("%d ", arr[find(i)][poyo[find(i)]++]);
  }
}