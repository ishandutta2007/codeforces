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

char buf[1000000];
main(){
  int cnt=0,ans=0;
  while(gets(buf)){
    if(buf[0]=='-')cnt--;else if(buf[0]=='+')cnt++;else{
       int pos=0;
       while(buf[pos]&&buf[pos]!=':')pos++;
       if(!buf[pos])break;
       ans+=cnt*(strlen(buf)-pos-1); 
    }
  }
  printf("%d\n",ans);
}