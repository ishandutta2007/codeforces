#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  string S[1000], T[2000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i] >> T[i];
    while(S[i].size() > 3) S[i].pop_back();
    while(T[i].size() > 1) T[i].pop_back();
    T[i] = S[i].substr(0, 2) + T[i];
  }

  map< string, vector< int > > g;
  queue< int > que;
  int mark[1000] = {};

  for(int i = 0; i < N; i++) g[S[i]].push_back(i);
  for(int i = 0; i < N; i++) {
    if(g[S[i]].size() >= 2) mark[i] = true, que.push(i);
  }

  while(!que.empty()) {
    int p = que.front();
    que.pop();
    for(int i : g[T[p]]) {
      if(!mark[i]) mark[i] = true, que.push(i);
    }
  }

  string choose[1000];
  for(int i = 0; i < N; i++) {
    choose[i] = mark[i] ? T[i] : S[i];
    for(int j = 0; j < i; j++) {
      if(choose[i] == choose[j]) {
        cout << "NO" << endl;
        return (0);
      }
    }
  }

  cout << "YES" << endl;
  for(int i = 0; i < N; i++) cout << choose[i] << endl;

}