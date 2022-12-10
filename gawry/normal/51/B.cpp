#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int pos;
vector<int> r;
void table();
int row(){
  pos+=4;
  int len=0;
  while(s[pos+1]!='/'){
    pos+=4;
    if(s[pos+1]!='/')table();
    pos+=5;
    len++;
  }
  pos+=5;
  return len;
}
void table(){
  pos+=7;
  int cells=0;
  while(s[pos+1]!='/'){
    cells+=row(); 
  }
  r.push_back(cells);
  pos+=8;
}
main(){
  string t;
  while(cin>>t)s+=t;
  while(pos<s.size())table();
  sort(r.begin(),r.end());
  for(int i=0;i<r.size();i++){
    if(i)printf(" ");
    printf("%d",r[i]); 
  }
  puts("");
}