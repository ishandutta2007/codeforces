#include <bits/stdc++.h>

using namespace std;

vector< int > beet[456976][4];

int main()
{
  string S;
  cin >> S;

  for(int i = 0; i < S.size(); i++) {
    int hashed = 0;
    for(int j = 0; j < 4; j++) {
      if(i + j >= S.size()) break;
      hashed = hashed * 26 + S[i + j] - 'a';
      beet[hashed][j].push_back(i);
    }
  }

  int Q;
  cin >> Q;

  map< tuple< int, int, int, int >, int > dp;

  while(Q--) {
    string A, B;
    cin >> A >> B;
    if(A.size() > B.size()) swap(A, B);

    int latte = 0, malta = 0;
    for(char p : A) latte = latte * 26 + p - 'a';
    for(char p : B) malta = malta * 26 + p - 'a';

    auto &p = beet[latte][A.size() - 1];
    auto &q = beet[malta][B.size() - 1];

    int n = A.size(), m = B.size();

    if(p.empty() || q.empty()) {
      cout << -1 << endl;
    } else if(dp.count({latte, malta, n, m})) {
      cout << dp[{latte, malta, n, m}] << endl;
    } else {
      int tail = 0, ret = 11451419;
      for(int i = 0; i < p.size(); i++) {
        while(tail < q.size() && q[tail] < p[i]) ++tail;
        if(tail < q.size()) {
          ret = min(ret, max(p[i] + n, q[tail] + m) - min(p[i], q[tail]));
        }
        if(tail > 0) {
          ret = min(ret, max(p[i] + n, q[tail - 1] + m) - min(p[i], q[tail - 1]));
        }
      }
      dp[{latte, malta, n, m}] = ret;
      cout << ret << endl;
    }
  }

}