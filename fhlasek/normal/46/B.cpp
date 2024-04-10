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

int a[5];

bool t(int s){
  if(s<5&&s>=0){
    if(a[s]){
      a[s]--;
      return true;
    }
  }
  return false;
}

int get(int s){
  if(t(s)) return s;
  if(t(s+1)) return s+1;
  if(t(s-1)) return s-1;
  if(t(s+2)) return s+2;
  if(t(s-2)) return s-2;
  if(t(s+3)) return s+3;
  if(t(s-3)) return s-3;
  if(t(s+4)) return s+4;
  if(t(s-4)) return s-4;
  return -1;
}

int main(int argc, char *argv[]){
  int K,i,r;
  char line[5];
  scanf("%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,&K);
  FOR(i,K){
    scanf("%s",line);
    if(line[0]=='S') r=get(0);
    else{
      if(line[0]=='M') r=get(1);
      else{
        if(line[0]=='L') r=get(2);
        else{
          if(line[1]=='L') r=get(3);
          else r=get(4);
        }
      }
    }
    if(r==0) printf("S\n");
    if(r==1) printf("M\n");
    if(r==2) printf("L\n");
    if(r==3) printf("XL\n");
    if(r==4) printf("XXL\n");
  }
  return 0;
}