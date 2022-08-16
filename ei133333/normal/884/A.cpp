#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N, T;

  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    T -= 86400 - A;
    if(T <= 0) {
      cout << i + 1 << endl;
      return(0);
    }
  }

}