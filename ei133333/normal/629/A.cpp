#include<bits/stdc++.h>
using namespace std;


int main()
{
  int N;
  int row[100] = {}, col[100] = {};
  cin >> N;
  for(int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for(int j = 0; j < S.size(); j++) {
      if(S[j] == 'C') ++row[j], ++col[i];
    }
  }
  long long ret = 0;
  for(int i = 0; i < N; i++) {
    ret += row[i] * (row[i] - 1) / 2;
    ret += col[i] * (col[i] - 1) / 2;
  }
  cout << ret << endl;
}