#include <bits/stdc++.h>

using namespace std;

int main()
{
  int K;
  string N;

  cin >> K;
  cin >> N;
  sort(begin(N), end(N));

  for(auto &s : N) K -= s - '0';

  int diff = 0;
  for(auto &s : N) {
    int rest = 9 - (s - '0');
    if(K > 0) {
      K -= rest;
      ++diff;
    }
  }

  cout << diff << endl;
}