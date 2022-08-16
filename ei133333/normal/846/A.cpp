#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[100];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ret = 0;
  for(int i = -1; i < N; i++) {
    int beet = 0;
    for(int j = 0; j <= i; j++) {
      if(A[j] == 0) ++beet;
    }
    for(int j = i + 1; j < N; j++) {
      if(A[j] == 1) ++beet;
    }
    ret = max(ret, beet);
  }

  cout << ret << endl;
}