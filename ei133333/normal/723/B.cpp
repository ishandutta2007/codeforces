#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;

  int kakko = 0, res = 0;
  int max_length = 0, count = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] == '(') {
      res = 0;
      ++kakko;
    } else if(S[i] == ')') {
      if(res > 0) ++count;
      res = 0;
      --kakko;
    } else if(S[i] == '_') {
      if(kakko > 0 && res > 0) ++count;
      res = 0;
    } else {
      ++res;
      if(kakko == 0) max_length = max(max_length, res);
    }
  }

  cout << max_length << " " << count << endl;
}