#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A, B;
  string S;

  cin >> N >> A >> B;
  cin >> S;
  int ptr = 0;
  int ret = 0;
  while(ptr < S.size()) {
    if(S[ptr] == '*') {
      ++ptr;
      continue;
    } else {
      if(A < B) swap(A, B);
      while(ptr < S.size() && S[ptr] == '.') {
        --A;
        if(A >= 0) ++ret;
        swap(A, B);
        ++ptr;
      }
    }
  }
  cout << ret << endl;
}