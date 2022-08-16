#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  string S;
  cin >> S;
  int M;
  cin >> M;
  while(M--) {
    int L, R, K;
    cin >> L >> R >> K;
    --L;
    K%=R-L;
    K=(R-L)-K;
    K%=R-L;
    rotate(S.begin()+L,S.begin()+L+K, S.begin()+R);
  }
  cout << S << endl;
}