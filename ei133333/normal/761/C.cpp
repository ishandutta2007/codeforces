#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  string S[50];

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> S[i];

  vector< int > a, b, c;
  for(int i = 0; i < N; i++) {
    int aa = 114514, bb = 114514, cc = 114514;
    for(int j = 0; j < S[i].size(); j++) {
      if(isdigit(S[i][j])) aa = min(aa, min(j, M - j));
      else if(isalpha(S[i][j])) bb = min(bb, min(j, M - j));
      else cc = min(cc, min(j, M - j));
    }
    a.push_back(aa);
    b.push_back(bb);
    c.push_back(cc);
  }

  int ret = 114514;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        if(i == j || i == k || j == k) continue;
        ret = min(ret, a[i] + b[j] + c[k]);
      }
    }
  }

  cout << ret << endl;

}