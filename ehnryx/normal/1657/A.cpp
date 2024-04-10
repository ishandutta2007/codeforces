#include<bits/stdc++.h>
using namespace std;main(){
  int t;cin>>t;while(t--){
    int a,b;cin>>a>>b;
    int h=a*a+b*b;
    int s=sqrt(h);
    if(a==0&&b==0)cout<<"0\n";
    else if(s*s==h){
      cout<<"1\n";
    }else cout<<"2\n";
  }
}