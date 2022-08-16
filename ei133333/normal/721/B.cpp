#include<bits/stdc++.h>

using namespace std;

int score(int N, int K)
{
  return((N - 1) / K * 5 + N);
}

int main()
{
  int N, K;
  string S[101], T;
  int length[101] = {};

  cin >> N >> K;
  for(int i = 0; i < N; ++i) {
    cin >> S[i];
    ++length[S[i].size()];
  }
  cin >> T;

  int sum = accumulate(length, length + T.size(), 0);
  cout << score(sum + 1, K) << " " << score(sum + length[T.size()], K) << endl;
}