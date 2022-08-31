#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N, X;
  cin >> N >> X;

  if(N == 1) {
    cout << "YES" << endl;
    cout << X << endl;
    return (0);
  } else if(N == 2) {
    if(X == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << X << " " << 0 << endl;
    }
    return (0);
  }

  vector< int > ans;

  vector< int > mask;
  mask.push_back(0);
  if(N % 2 == 0) {
    for(int i = 1; i < N; i++) {
      int bit = 0;
      if(i != N - 1) bit |= 1 << 19;
      if(i != 1) bit |= 1 << 18;
      mask.push_back(bit);
    }
  } else {
    for(int i = 1; i < N; i++) {
      int bit = 0;
      bit |= 1 << 18;
      mask.push_back(bit);
    }
  }

  cout << "YES" << endl;
  int flag = X;
  for(int i = 1; i < N; i++) {
    flag ^= i;
    cout << (i | mask[i]) << " ";
  }
  cout << flag << endl;
}