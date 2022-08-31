#include<bits/stdc++.h>
using namespace std;

vector< int > graph[200000];
int v[200000];

int main()
{
  int N;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    graph[i].push_back(--A);
  }
  for(int i = 0; i < N - 1; i++) {
    graph[i].push_back(i + 1);
    graph[i + 1].push_back(i);
  }

  queue< int > que;
  
  memset(v, -1, sizeof(v));
  v[0] = 0;
  que.push(0);
  
  while(!que.empty()) {
    int p = que.front(); que.pop();
    for(int to : graph[p]) {
      if(~v[to]) continue;
      v[to] = v[p] + 1;
      que.push(to);
    }
  }
  for(int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
}