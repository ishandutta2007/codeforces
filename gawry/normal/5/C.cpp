#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

char buf[1010*1010];
int s[1010*1010],m[1010*1010];
main(){
  scanf("%s",buf);
  int n=strlen(buf),ans=0,cnt=1;
  vector<int> p(1);
  m[0]=1;
  for(int i=1;i<=n;i++){
    s[i]=s[i-1]+(buf[i-1]=='('?1:-1);
    while(!p.empty()&&s[p.back()]>s[i])p.pop_back();
    if(p.empty()||s[p.back()]<s[i]){m[i]=1;p.push_back(i);continue;}
    if(i-p.back()>ans){
       ans=i-p.back(); 
       cnt=m[p.back()];
    }else if(i-p.back()==ans){
      cnt+=m[p.back()];
    }
    m[i]++;
  }
  printf("%d %d\n",ans,cnt);
}