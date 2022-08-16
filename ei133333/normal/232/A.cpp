#include<bits/stdc++.h>

using namespace std;

const int SZ = 100;

int main()
{
  bool g[SZ][SZ] = {{}};
  int N;
  cin >> N;
  for(int i = 0; i < SZ; i++) {
    for(int j = 0; j < i; j++) {
      int ret = 0;
      for(int k = 0; k < SZ; k++) if(g[j][k] && g[i][k]) ++ret;
      if(ret <= N) {
        g[i][j] = g[j][i] = true;
        N -= ret;
      }
    }
  }

  cout << SZ << endl;
  for(int i = 0; i < SZ; i++) {
    for(int j = 0; j < SZ; j++) cout << g[i][j];
    cout << endl;
  }
}