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

int main(int argc, char *argv[]){
  int a,o=0,n; 
  scanf("%d",&n);
  REP(i,n){
    scanf("%d",&a);
    if(a%2) o++;
  }
  if(o%2) printf("%d",o);
  else    printf("%d",n-o);
  return 0;
}