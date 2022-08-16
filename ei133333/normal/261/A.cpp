#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int M, Q[100000], N, A[100000];

  cin >> M;
  for(int i = 0; i < M; i++) cin >> Q[i];
  sort(Q, Q + M);
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  queue< int > que;
  for(int i = N - 1; i >= 0; i--) que.emplace(A[i]);

  int64 ret = 0, tail = 0;
  while(!que.empty()) {
    for(int i = 0; i < Q[tail] && !que.empty(); i++) {
      ret += que.front();
      que.pop();
    }
    for(int i = 0; i < 2 && !que.empty(); i++) {
      que.pop();
    }
  }
  while(!que.empty()) {
    ret += que.front();
    que.pop();
  }

  cout << ret << endl;

}