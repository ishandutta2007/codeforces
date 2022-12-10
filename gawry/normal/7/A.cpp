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
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

char s[10][10];
int main() {
  FOR(i,8)scanf(" %s",s[i]);
  int ans=100;
  FOR(x,1<<8){
    int y=0;
    FOR(i,8)if(!(x&1<<i))FOR(j,8)if(s[i][j]=='B')y|=1<<j;
    bool ok=1;
    FOR(i,8)FOR(j,8)ok&=(s[i][j]=='B')==((x&1<<i)||(y&1<<j));
    if(ok)ans=min(ans,__builtin_popcount(x)+__builtin_popcount(y)); 
  }
  printf("%d\n",ans);
  return 0;
}