#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  while(N--) {
    int X;
    cin >> X;

    for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
        if(i * 3 + j * 7 == X) {
          cout << "YES" << endl;
          goto LatteMalta;
        }
      }
    }
    cout << "NO" << endl;
    LatteMalta:;
  }
}