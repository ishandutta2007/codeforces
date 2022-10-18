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

int main(int argc, char *argv[]){
  char c;
  int sum=0,opens=0;
  while(scanf("%c",&c)!=EOF){
    if(c!='('&&c!=')') break;
    if(c=='(') opens++;
    else{
      if(opens){
        opens--;
        sum+=2;
      }
    }
  }
  printf("%d\n",sum);
  return 0;
}