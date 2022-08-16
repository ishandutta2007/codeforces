#include<bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int update[300000];
  bool del[300000] = {};
  int reordered = 0;
  int ret = 0;

  stack< int > st;
  int now = 0;

  for(int i = 0; i < 2 * N; i++) {
    string q;
    cin >> q;
    if(q == "add") {
      int k;
      cin >> k;
      --k;
      update[k] = i;
      st.push(k);
    } else {
      while(!st.empty() && del[st.top()]) st.pop();
      del[now] = true;
      if(st.top() != now && update[st.top()] > reordered) {
        reordered = i;
        ++ret;
      }
      ++now;
    }
  }

  cout << ret << endl;
}