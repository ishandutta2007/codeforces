#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string a, b;
int main(){
  cin>>a>>b;
  int ans=a.length()+b.length();
  int ptra=a.length()-1;
  int ptrb=b.length()-1;
  while(ptra>=0 and ptrb>=0){
    if(a[ptra]==b[ptrb]){
      ans-=2;
      ptra--;
      ptrb--;
    }else break;
  }
  cout<<ans<<endl;
}