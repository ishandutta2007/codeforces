#include <bits/stdc++.h>

using namespace std;


using int64 = long long;

int main()
{
  int N;
  cin >> N;

  int x[100] = {};
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      for(int k = i; k < j; k++) {
        ++x[k];
      }
    }
  }
  cout << *max_element(x, x + N) << endl;
}