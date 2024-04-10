#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3;
int N;
char S[MAXN];
int main() {
  cin >> N >> S;
  for (int i = 0; i+1 < N; i++) {
    if (S[i] != S[i+1]) { cout << "YES\n" << S[i] << S[i+1] << '\n'; return 0; }
  }
  cout << "NO\n";
  return 0;
}