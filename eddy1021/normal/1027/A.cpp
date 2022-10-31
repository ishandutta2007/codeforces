#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
bool ok(){
  int len=s.length();
  for(int l=0, r=len-1; l<r; l++, r--){
    bool g=false;
    for(int j=-1; j<=1; j+=2)
      for(int k=-1; k<=1; k+=2){
        if(s[l]+j < 'a' or s[l]+j > 'z') continue;
        if(s[r]+k < 'a' or s[r]+k > 'z') continue;
        if(s[l]+j == s[r]+k) g=true;
      }
    if(not g) return false;
  }
  return true;
}
int main(){
  int t, n;
  cin>>t; while(t--){
    cin>>n>>s;
    cout<<(ok()?"YES":"NO")<<endl;
  }
}