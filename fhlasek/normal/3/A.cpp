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
  char a[3],b[3];
  scanf("%s",a);
  scanf("%s",b);
  int a1,a2,b1,b2,i;
  a1=a[0]-'a';
  a2=a[1]-'1';
  b1=b[0]-'a';
  b2=b[1]-'1';
  printf("%d\n",max(abs(a1-b1),abs(a2-b2)));
  if(abs(a1-b1)>abs(a2-b2)){
    if(a1>b1){
      if(a2>b2) FOR(i,abs(a2-b2)) printf("LD\n");
      else      FOR(i,abs(a2-b2)) printf("LU\n");
      FOR(i,abs(a1-b1)-abs(a2-b2)) printf("L\n");
    }
    else{
      if(a2>b2) FOR(i,abs(a2-b2)) printf("RD\n");
      else      FOR(i,abs(a2-b2)) printf("RU\n");
      FOR(i,abs(a1-b1)-abs(a2-b2)) printf("R\n");
    }
  }
  else{
    if(a2>b2){
      if(a1>b1) FOR(i,abs(a1-b1)) printf("LD\n");
      else      FOR(i,abs(a1-b1)) printf("RD\n");
      FOR(i,abs(a2-b2)-abs(a1-b1)) printf("D\n");
    }
    else{
      if(a1>b1) FOR(i,abs(a1-b1)) printf("LU\n");
      else      FOR(i,abs(a1-b1)) printf("RU\n");
      FOR(i,abs(a2-b2)-abs(a1-b1)) printf("U\n");
    }
  }
  return 0;
}