#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

typedef long long int64;
typedef pair<int,int> p2;
typedef vector<int> vi;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int n,m;
int main() {
  scanf("%d %d",&n,&m);
  int from=1,to=n;
  FOR(i,m){
    char s[20];
    int x;
    scanf(" %*s %*s %s %*s %d",s,&x);
    if(s[0]=='r')from=max(from,x+1);
    else to=min(to,x-1);
  }
  if(from>to)puts("-1");else printf("%d\n",to-from+1);
  return 0;
}