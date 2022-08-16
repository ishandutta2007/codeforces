#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector< int > poyo(N);
  int num = 0;
  for(int i = 0; i < K - 1; i++) {
    poyo[i] = num++;
  }
  for(int i = K - 1; i < N; i++) {
    string S;
    cin >> S;
    if(S == "NO") poyo[i] = poyo[i - K + 1];
    else poyo[i] = num++;
  }

  for(int i = 0; i < N; i++) {
    cout << (char)('A' + poyo[i] / 26) << (char)(poyo[i] % 26 + 'a') << " ";
  }
  cout << endl;

}