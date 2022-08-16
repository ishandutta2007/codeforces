#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  for(int i = sqrt(N); i >= 0; i--) {
    if(N % i == 0) {
      cout << i << " " << N / i << endl;
      return(0);
    }
  }
}