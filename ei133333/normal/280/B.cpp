#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  stack< int > st;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    while(!st.empty()) {
      ret = max(ret, st.top() ^ A[i]);
      if(st.top() < A[i]) st.pop();
      else break;
    }
    st.push(A[i]);
  }

  cout << ret << endl;

}