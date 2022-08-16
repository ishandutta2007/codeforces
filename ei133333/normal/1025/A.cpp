#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  int sum[26] = {};
  for(int i = 0; i < N; i++) {
    sum[S[i] - 'a']++;
  }
  int one = 0, two = 0;
  for(int i = 0; i < 26; i++) {
    if(sum[i] == 1) ++one;
    else if(sum[i] > 1) ++two;
  }

  if(one <= 1) {
    cout << "Yes" << endl;
  } else {
    if(two == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}