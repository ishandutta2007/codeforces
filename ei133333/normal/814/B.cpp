#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[1000], B[1000];
  int v[1001] = {};

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i], v[A[i]]++;
  for(int i = 0; i < N; i++) cin >> B[i];

  int latte, malta;
  vector< int > beet;
  for(int i = 1; i <= N; i++) {
    if(v[i] == 0) latte = i;
    else if(v[i] == 2) malta = i;
  }
  for(int i = 0; i < N; i++) {
    if(v[A[i]] == 2) beet.push_back(i);
  }

  for(int s : beet) {
    A[s] = latte;
    int diff = 0;
    for(int j = 0; j < N; j++) diff += A[j] != B[j];
    if(diff == 1) {
      for(int j = 0; j < N; j++) cout << A[j] << " ";
      cout << endl;
      return(0);
    }
    A[s] = malta;
  }


}