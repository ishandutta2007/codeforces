#include <bits/stdc++.h>

using namespace std;

void fail()
{
  cout << "===\n";
  exit(0);
}

int main()
{
  int N;
  string S;
  const string temp = "ACGT";

  cin >> N;
  cin >> S;
  if(N % 4 != 0) fail();
  int odd = N / 4;
  for(int i = 0; i < 4; i++) {
    int sum = count(begin(S), end(S), temp[i]);
    if(sum > odd) fail();
    sum = odd - sum;
    for(int j = 0; j < S.size() && sum > 0; j++) {
      if(S[j] == '?') S[j] = temp[i], --sum;
    }
  }

  cout << S << endl;
}