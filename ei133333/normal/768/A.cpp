#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int big = *max_element(A, A + N);
  int small = *min_element(A, A + N);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] != big && A[i] != small) ++ret;
  }
  cout << ret << endl;
}