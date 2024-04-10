/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

char t,a[3],b[3]; 

bool beat(){
  if(a[1]!=b[1]){
    if(a[1]==t) return true;
    return false;
  }
  int A,B;
  A=a[0]-'0';
  if(a[0]=='T') A=10;
  if(a[0]=='J') A=11;
  if(a[0]=='Q') A=12;
  if(a[0]=='K') A=13;
  if(a[0]=='A') A=14;
  B=b[0]-'0';
  if(b[0]=='T') B=10;
  if(b[0]=='J') B=11;
  if(b[0]=='Q') B=12;
  if(b[0]=='K') B=13;
  if(b[0]=='A') B=14;
  return A>B;
}

int main(int argc, char *argv[]){
  scanf("%c",&t);
  scanf("%s",a);
  scanf("%s",b);
  if(beat()) printf("YES\n");
  else printf("NO\n");
  return 0;
}