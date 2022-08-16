#include<bits/stdc++.h>
using namespace std;


int main()
{
  int N;
  cin >> N;

  int imos1[368] = {}, imos2[368] = {};
  for(int i = 0; i < N; i++) {
    char S;
    int A, B;
    cin >> S >> A >> B;
    if(S == 'M') {
      ++imos1[A];
      --imos1[B + 1];
    } else {
      ++imos2[A];
      --imos2[B + 1];
    }
  }

  int ret = 0;
  for(int i = 1; i < 367; i++) {
    imos1[i] += imos1[i - 1];
    imos2[i] += imos2[i - 1];
    ret = max(ret, min(imos1[i], imos2[i]) * 2);
  }
  cout << ret << endl;
}