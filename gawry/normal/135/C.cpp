#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<string>
#include<vector>
#include<deque>
using namespace std;
int n;
char t[110000],tt[110000];
string calc(){
  //puts(tt);
  deque<int> s[2];
  for(int i=0;i<n;i++)s[tt[i]-'0'].push_back(i);
  int nr=1;
  while(s[0].size()+s[1].size()>2){
    if(s[nr].size()){
      tt[s[nr][0]]='.';
      s[nr].pop_front();
    }else{
      tt[s[nr^1][0]]='.';
      s[nr^1].pop_front();
    }
    nr^=1;
  }
  //puts(tt);
  string ans;
  for(int i=0;i<n;i++)if(tt[i]!='.')ans+=tt[i];
  return ans;
}
main(){
  scanf(" %s",t);
  n=strlen(t);
  for(int i=0;i<n;i++){
    tt[i]=t[i];
    if(tt[i]=='?')tt[i]='0';
  }
  set<string> ans;
  ans.insert(calc());
  for(int i=0;i<n;i++){
    tt[i]=t[i];
    if(tt[i]=='?')tt[i]='1';
  }
  ans.insert(calc());
  int needs[2]={n/2,n-n/2},has[2]={};
  for(int i=0;i<n;i++)if(t[i]!='?')++has[t[i]-'0'];
  if(has[0]<=needs[0]&&has[1]<=needs[1]){
    for(int i=0;i<n;i++){
      tt[i]=t[i];
      if(tt[i]=='?')if(has[0]<needs[0])tt[i]='0',++has[0];else tt[i]='1',++has[1];
    }
    ans.insert(calc());
    has[0]=has[1]=0;
    for(int i=0;i<n;i++)if(t[i]!='?')++has[t[i]-'0'];
    for(int i=0;i<n;i++){
      tt[i]=t[i];
      if(tt[i]=='?')if(has[1]<needs[1])tt[i]='1',++has[1];else tt[i]='0',++has[0];
    }
    ans.insert(calc());
  }
  for(set<string>::iterator it=ans.begin();it!=ans.end();it++)cout<<*it<<endl;
}