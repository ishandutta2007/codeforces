#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  S += "0";

  int sum = 0;
  for(auto &c : S) {
    if(c == '1') {
      ++sum;
    } else {
      cout << sum;
      sum = 0;
    }
  }
  cout << endl;

}