#include<bits/stdc++.h>
using namespace std;


int N, M, U[100001], V[100001];

int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> U[i] >> V[i];
  }
  int small = N, big = 1;
  for(int i = 0; i < M; i++) {
    small = min(small, max(U[i], V[i]));
    big   = max(big, min(U[i], V[i]));
  }
  cout << max(0, small - big) << endl;
}