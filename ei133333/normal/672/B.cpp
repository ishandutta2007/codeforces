#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  string S;
  cin >> N;
  cin >> S;
  if(S.size() > 26) {
    cout << -1 << endl;
  } else {
    int sum[26] = {};
    for(int i = 0; i < N; i++) ++sum[S[i] - 'a'];
    int ret = 0;
    for(int i = 0; i < 26; i++) ret += max(0, sum[i] - 1);
    cout << ret << endl;
  }
}