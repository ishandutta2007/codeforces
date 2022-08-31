#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  string S;

  cin >> N;
  cin >> S;

  map< int, int > pv;
  int sum = 0, ret = 0;
  pv[0] = -1;
  for(int i = 0; i < N; i++) {
    if(S[i] == '1') ++sum;
    else --sum;
    if(pv.count(sum)) ret = max(ret, i - pv[sum]);
    else pv[sum] = i;
  }

  cout << ret << endl;
}