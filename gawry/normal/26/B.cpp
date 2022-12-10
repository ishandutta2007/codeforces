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
#include<queue>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

char buf[1100000];
int n,r,c;
main() {
  gets(buf);
  n=strlen(buf);
  FOR(i,n)if(buf[i]=='(')c++,r++;else if(c){
    c--;
    r++;
  }
  r-=c;
  printf("%d\n",r);
}