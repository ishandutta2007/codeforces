// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> st;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        st.insert(a[i] - a[j]);
      }
    }
    cout << (int) st.size() << '\n';
  }
}