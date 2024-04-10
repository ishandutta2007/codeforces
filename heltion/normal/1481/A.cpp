#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    vector<int> v(256);
    for(char c : s) v[c] += 1;
    cout << (-v['L'] <= x and x <= v['R'] and -v['D'] <= y and y <= v['U'] ? "YES\n" : "NO\n");
  }
  return 0;
}