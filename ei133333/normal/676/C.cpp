#include<bits/stdc++.h>

using namespace std;

int N, K;
string S;

int cmp(char c)
{
  int ret = 1;

  int tail = 0, count = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] != c) ++count;
    while(tail < N && count > K) {
      if(S[tail] != c) --count;
      ++tail;
    }
    ret = max(ret, i - tail + 1);
  }
  return(ret);
}
int main()
{
  cin >> N >> K;
  cin >> S;
  cout << max(cmp('a'), cmp('b')) << endl;
}