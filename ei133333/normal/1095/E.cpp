#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  vector< int > latte(N), malta(N);
  vector< int > latteX(N), maltaX(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    sum += S[i] == '(' ? 1 : -1;
    latte[i] = sum;
    if(sum < 0) latteX[i] = true;
    if(i > 0 && latteX[i - 1]) latteX[i] = true;
  }
  sum = 0;
  for(int i = N - 1; i >= 0; i--) {
    sum += S[i] == ')' ? 1 : -1;
    malta[i] = sum;
    if(sum < 0) maltaX[i] = true;
    if(i + 1 < N && maltaX[i + 1]) maltaX[i] = true;
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    int p = i == 0 ? 0 : latte[i - 1];
    int q = i + 1 == N ? 0 : malta[i + 1];
    if(i > 0 && latteX[i - 1]) continue;
    if(i + 1 < N && maltaX[i + 1]) continue;

    p += (S[i] == ')' ? 1 : -1);
    if(p < 0) continue;
    if(q + (S[i] == '(' ? 1 : -1) < 0) continue;


    if(p - q == 0) ++ret;
  }

  cout << ret << endl;
}