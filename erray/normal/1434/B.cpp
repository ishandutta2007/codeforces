// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> q(2 * n);
  vector<int> st;
  auto imp = [&] {
    cout << "NO\n";
    exit(0);
  };

  for (int i = 0; i < 2 * n; ++i) {
    char c;
    cin >> c;
    if (c == '+') {
      st.push_back(i);
    } else {
      int v;
      cin >> v;
      if (st.empty()) {
        imp();
      }

      q[i] = v;
      q[st.back()] = -v;
      st.pop_back();    
    }
  }
  priority_queue<int> pq;
  vector<int> ans;

  for (int i = 0; i < 2 * n; ++i) {
    if (q[i] < 0) {
      pq.push(q[i]);
      ans.push_back(-q[i]);
    } else {
      if (-q[i] != pq.top()) {
        imp();
      }
      pq.pop();
    }  
  }
  cout << "YES\n";
  for (auto el : ans) {
    cout << el << ' ';
  }
}