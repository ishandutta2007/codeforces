#include<bits/stdc++.h>

using namespace std;
const double EPS = 1e-14;

int N, T;
long double ptr[100][100] = {{}};

int main()
{

  cin >> N >> T;

  ptr[0][0] = T;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      ptr[i + 1][j] += max((long double)0.0, (ptr[i][j] - 1.0) / 2.0);
      ptr[i + 1][j + 1] += max((long double)0.0f, (ptr[i][j] - 1.0) / 2.0);
    }
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(ptr[i][j] >= 1.0 - EPS) ++ret;
    }
  }
  cout << ret << endl;
}