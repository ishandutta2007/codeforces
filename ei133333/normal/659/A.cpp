#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  if(B >= 0) {
    while(B > 0) {
      A++;
      if(A == N + 1) A = 1;
      --B;
    }
  } else {
    B = -B;
    while(B > 0) {
      A--;
      if(A == 0) A = N;
      --B;
    }
  }  
  cout << A << endl;
}