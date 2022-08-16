#include <bits/stdc++.h>

using namespace std;

int N, X[2000], Y[2000];
bool beet[20000001];

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i], beet[X[i]] = true;
  }
  for(int i = 0; i < N; i++) {
    cin >> Y[i], beet[Y[i]] = true;
  }
  bool flag = false;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      flag ^= beet[X[i] ^ Y[j]];
    }
  }
  if(!flag) cout << "Karen" << endl;
  else cout << "Koyomi" << endl;
}