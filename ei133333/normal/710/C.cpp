#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int even = 2, odd = 1;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(abs(i - N / 2) + abs(j - N / 2) <= N / 2) {
        cout << odd << " ";
        odd += 2;
      } else {
        cout << even << " ";
        even += 2;
      }
    }
    cout << endl;
  }
}