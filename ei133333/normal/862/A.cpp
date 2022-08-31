#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  set< int > st;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    st.emplace(x);
  }

  int ret = 0;
  for(int i = 0; i < K; i++) {
    if(!st.count(i)) ++ret;
  }
  if(st.count(K)) ++ret;

  cout << ret << endl;
}