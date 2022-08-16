#include<bits/stdc++.h>
using namespace std;

int main()
{   
  int N, M;
  cin >> N >> M;

  bool light[100] = {};
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    while(K--) {
      int Y;
      cin >> Y;
      light[--Y] = true;
    }
  }

  if(count(light, light + M, true) == M) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}