#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, K, A, B, C, D;
  
  
  cin >> N >> K;
  cin >> A >> B >> C >> D;
  --A, --B, --C, --D;
  
  if(K <= N || N == 4) {
    cout << -1 << endl;
  } else {
    vector< int > Array;
    Array.push_back(A);
    Array.push_back(C);
    for(int i = 0; i < N; i++) {
      if(i != A && i != B && i != C && i != D) {
        Array.push_back(i);
      }
    }
    Array.push_back(D);
    Array.push_back(B);
    for(int i = 0; i < N; i++) {
      if(i > 0) cout << " ";
      cout << Array[i] + 1;
    }
    cout << endl;

    cout << Array[1] + 1 << " ";
    cout << Array[0] + 1 << " ";
    cout << Array[2] + 1 << " ";
    for(int i = 3; i < N - 2; i++) cout << Array[i] + 1 << " ";
    cout << Array[N - 1] + 1 << " ";
    cout << Array[N - 2] + 1 << endl;
  }
}