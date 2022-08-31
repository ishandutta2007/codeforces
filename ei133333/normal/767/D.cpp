#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int F[10000001];
vector< int > S[10000001];

int main()
{


  scanf("%d %d %d", &N, &M, &K);
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    F[A]++;
  }
  for(int i = 0; i < M; i++) {
    int A;
    scanf("%d", &A);
    S[A].push_back(i + 1);
  }

  int need = 0; // 
  queue< int > vs, que;
  for(int i = 10000000; i >= 0; i--) {
    need += F[i];
    int space = K - min(need, K);

    need -= min(need, K);
    for(int j = 0; j < S[i].size(); j++) {
      que.push(S[i][j]);
    }
    while(!que.empty() && space > 0) {
      vs.push(que.front());
      que.pop();
      --space;
    }
  }

  if(need > 0) {
    cout << -1 << endl;
  } else {
    cout << vs.size() << endl;
    while(!vs.empty()) {
      cout << vs.front() << " ";
      vs.pop();
    }
    cout << endl;
  }

}