#include<bits/stdc++.h>

using namespace std;


int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  int ret = N;
  for(int i = 1; i < S.size(); i++) {
    if(S.substr(0, i) == S.substr(i, i)) {
      ret = min(ret, i + 1 + N - 2 * i);
    }
  }
  cout << ret << endl;
}