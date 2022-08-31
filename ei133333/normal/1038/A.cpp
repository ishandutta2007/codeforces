#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  int ret = 0;
  vector< int > buff(26);
  for(int i = 0; i < N; i++) buff[S[i] - 'A']++;
  sort(buff.rbegin(), buff.rend());
  for(int j = K-1; j < 26; j++) ret = max(ret, buff[j] * (j + 1));
  cout << ret << endl;
}