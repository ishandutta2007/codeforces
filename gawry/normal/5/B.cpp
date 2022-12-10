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

char buf[1010][1010];
main(){
  int n=0,m=0;
  while(gets(buf[n]))n++;
  for(int i=0;i<n;i++)m=max(m,(int)strlen(buf[i]));
  for(int i=0;i<=m+1;i++)printf("*");puts("");
  int left=1;
  for(int i=0;i<n;i++){printf("*");if((m+strlen(buf[i]))%2)left^=1;int tmp=(m-strlen(buf[i])+left)/2;for(int j=0;j<tmp;j++)printf(" ");printf("%s",buf[i]);for(int j=m-tmp-strlen(buf[i]);j>0;j--)printf(" ");puts("*");}
  for(int i=0;i<=m+1;i++)printf("*");puts("");
}