/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char lucky[111];

int main(int argc, char *argv[]){
  int N,s1=0,s2=0; 
  scanf("%d",&N);
  scanf("%s",lucky);
  bool ok=true;
  REP(i,N) if(lucky[i]!='4'&&lucky[i]!='7') ok = false;
  REP(i,N/2){
    s1 += lucky[i]-'0';
    s2 += lucky[i+N/2]-'0';
  }
  if(ok&&s1==s2) printf("YES\n");
  else printf("NO\n");
  return 0;
}