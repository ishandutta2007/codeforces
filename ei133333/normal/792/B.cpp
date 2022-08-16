#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K;
  cin >> N >> K;
  vector< int > A(N);
  for(int i = 0; i < N; i++) A[i] = i + 1;

  int leader = 0;
  for(int i = 0; i < K; i++) {
    int S;
    cin >> S;

    int del = (leader + S) % A.size();
    cout << A[del]<< " ";

    vector< int > next;
    for(int j = 0; j < A.size(); j++) {
      if(del == j) continue;
      next.push_back(A[j]);
    }
    leader = del;
    swap(A, next);
  }

  cout << endl;
}