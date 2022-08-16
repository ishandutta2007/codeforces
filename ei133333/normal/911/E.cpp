#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, K, A[200000];
  cin >> N >> K;
  stack< int > st;
  st.push(INF);
  vector< int > array{0};
  set< int > rest;
  for(int i = 0; i < N; i++) rest.emplace(i + 1);
  for(int i = 0; i < K; i++) {
    cin >> A[i];
    rest.erase(A[i]);
    while(st.top() < A[i]) {
      array.emplace_back(st.top());
      st.pop();
    }
    st.push(A[i]);
  }

  for(int i = K; i < N; i++) {
    while(array.back() + 1 == st.top()) {
      array.push_back(st.top());
      st.pop();
    }
    int p = array.back() - 1;

    auto x = rest.lower_bound(st.top());

    if(x == rest.begin()) {
      cout << -1 << endl;
      return (0);
    }
    --x;
    A[i] = *x;
    st.emplace(*x);
    rest.erase(x);
  }

  while(st.size() > 1) {
    array.push_back(st.top());
    st.pop();
  }
  if(is_sorted(begin(array), end(array))) {
    for(int i = 0; i < N; i++) {
      printf("%d ", A[i]);
    }
    puts("");
  } else {
    cout << -1 << endl;
  }
}