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
  char seq[100001];
  char a[101];
  char b[101];
  scanf("%s",seq);
  scanf("%s",a);
  scanf("%s",b);
  int i,j;
  bool forward=false,back=false,ok;
  int N=0; 
  for(i=0;seq[i]>='a'&&seq[i]<='z';i++) N++;
  for(i=0;i<N;i++){
    ok=true;
    for(j=0;a[j]>='a'&&a[j]<='z';j++) if(seq[i+j]!=a[j]){ ok=false; break;}
    if(ok){
      for(i=i+j;i<N;i++){
        ok=true;
        for(j=0;b[j]>='a'&&b[j]<='z';j++) if(seq[i+j]!=b[j]){ ok=false; break;}
        if(ok){
          forward=true;
          break;
        }
      }
      break;
    }
  }
  for(i=N-1;i>=0;i--){
    ok=true;
    for(j=0;a[j]>='a'&&a[j]<='z';j++) if(i-j<0||seq[i-j]!=a[j]){ ok=false; break;}
    if(ok){
      for(i=i-j;i>=0;i--){
        ok=true;
        for(j=0;b[j]>='a'&&b[j]<='z';j++) if(i-j<0||seq[i-j]!=b[j]){ ok=false; break;}
        if(ok){
          back=true;
          break;
        }
      }
      break;
    }
  }
  if(forward&&back){printf("both\n"); return 0;}
  if(forward){printf("forward\n"); return 0;}
  if(back){printf("backward\n"); return 0;}
  printf("fantasy\n");
  return 0;
}