#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<iostream>
using namespace std;
string f(string s){
  string best=s;
  for(int i=0;i<4;i++){    
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        if(s<best)best=s;
        char tmp=s[1];
        s[1]=s[4];
        s[4]=s[3];
        s[3]=s[5];
        s[5]=tmp;
      }
      char tmp=s[0];
      s[0]=s[4];
      s[4]=s[2];
      s[2]=s[5];
      s[5]=tmp;
    }
    char tmp=s[0];
    for(int k=0;k<3;k++)s[k]=s[k+1];
    s[3]=tmp;
  }
  return best;
}
main(){
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  int cnt=0;
  do{
    cnt+=f(s)==s;
  }while(next_permutation(s.begin(),s.end()));
  cout<<cnt<<endl;
}