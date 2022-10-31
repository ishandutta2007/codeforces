// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
string gen(int x){
  string ret;
  while(x--) ret+="1";
  return ret;
}
int main(){
  cin>>s;
  string ans;
  int cnt1=0;
  for(char c: s){
    if(c=='1'){
      cnt1++;
      continue;
    }
    ans+=c;
  }
  if(ans.empty()){
    ans=gen(cnt1);
  }else{
    if(ans[0]=='2'){
      ans=gen(cnt1)+ans;
    }else{
      int ptr=0;
      int len=ans.length();
      while(ptr<len and ans[ptr]=='0') ptr++;
      ans=ans.substr(0, ptr)+gen(cnt1)+ans.substr(ptr,len);
    }
  }
  cout<<ans<<endl;
}