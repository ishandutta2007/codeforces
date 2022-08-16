#include<bits/stdc++.h>

using namespace std;


int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  int sum = 0;
  for(int i = 0; i < S.size() - 1; i++) {
    if((S[i + 1] == 'R' && S[i] == 'U') ||
       (S[i + 1] == 'U' && S[i] == 'R')) {
      ++i;
      --sum;
    }
  }
  cout << N + sum << endl;

}