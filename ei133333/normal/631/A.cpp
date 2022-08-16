#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N, A[1000], B[1000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int64 AA = 0, BB = 0;
    for(int j = i; j < N; j++) {
      AA |= A[j];
      BB |= B[j];
      ret = max(ret, AA + BB);
    }
  }
  cout << ret << endl;
}