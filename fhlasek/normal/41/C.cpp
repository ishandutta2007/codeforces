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

char line[111];

int main(int argc, char *argv[]){
  int L,i;
  scanf("%s",line); 
  for(L=0;line[L]!='\0';L++);
  bool at=false;
  printf("%c",line[0]);
  for(i=1;i<L-2;i++){
    if(line[i]=='a'&&line[i+1]=='t'&&!at){
      printf("@");
      at=true;
      i++;
      continue;
    }
    if(line[i]=='d'&&line[i+1]=='o'&&line[i+2]=='t'&&i+2<L-1){
      printf(".");
      i+=2;
      continue;
    }
    printf("%c",line[i]);
  }
  for(;i<L;i++) printf("%c",line[i]);
  printf("\n");
  return 0;
}