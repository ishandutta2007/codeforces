#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<LL> v(maxn);
  for(LL i = 0; i < maxn; i += 1) v[i] = (i + 1) * (i + 1) * (i + 1);
  int t;
  for(cin >> t; t; t -= 1){
    LL x;
    cin >> x;
    int ans = 0;
    for(int i = 0, j = maxn - 1;;){
      if(v[i] + v[j] == x){
        ans = 1;
        break;
      }
      if(v[i] + v[j] > x){
        if(j == 0) break;
        j -= 1;
      }
      else{
        if(i == maxn - 1) break;
        i += 1;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}