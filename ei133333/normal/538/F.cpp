#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[200005], latte[200005] = {};


  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }


  for(int i = 1; i < N; i++) {
    for(int j = 1; j < N; j++) {
      int par = (i - 1) / j;
      int range = (par == 0 ? N - 1 : (i - 1) / par);
      if(A[par] > A[i]) {
        ++latte[j];
        --latte[range + 1];
      }
      j = range;
    }
  }

  for(int i = 1; i < N; i++) {
    latte[i] += latte[i - 1];
    cout << latte[i] << endl;
  }

}