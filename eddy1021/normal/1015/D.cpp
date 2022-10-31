#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, s;
int main(){
  cin>>n>>k>>s;
  if(s < k){
    puts("NO");
    exit(0);
  }
  vector<LL> ans;
  LL cur=1;
  for(int i=1; i<=k; i++){
    if(s >= n-1 and 
       s-(n-1) >= k-i){
      if(cur == 1){
        ans.push_back(n);
        cur=n;
      }else{
        ans.push_back(1);
        cur=1;
      }
      s-=n-1;
      continue;
    }
    if(s == k-i+1){
      if(cur == 1){
        ans.push_back(2);
        cur=2;
      }else{
        ans.push_back(--cur);
      }
      s--;
      continue;
    }
    LL nd=s-(k-i);
    if(cur + nd <= n){
      ans.push_back(cur + nd);
      cur+=nd;
      s-=nd;
      continue;
    }
    if(cur -nd >= 1){
      ans.push_back(cur - nd);
      cur-=nd;
      s-=nd;
      continue;
    }
    assert(false);
  }
  if(s){
    puts("NO");
    exit(0);
  }
  puts("YES");
  for(auto i: ans) printf("%lld ", i);
  puts("");
}