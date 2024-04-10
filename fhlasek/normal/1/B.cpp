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

char line[111];
int L;

void solve(){
  int posc = -1;
  REP(i,L) if(line[i]=='C') posc = i;
  if(line[0]=='R' && line[1] >= '0' && line[1] <= '9' && posc > 1){
    int a = 0,b = 0;
    FOR(i,1,posc-1) a = 10*a + (line[i] - '0');
    FOR(i,posc+1,L-1) b = 10*b + (line[i] - '0');
    char res[20];
    int R=0;
    while(b){ res[R++] = (b-1)%26 + 'A'; b=(b-1)/26; }
    FORD(i,R-1,0) printf("%c",res[i]);
    printf("%d\n",a);
  }
  else{
    int a = 0,b = 0,i = 0;
    for(i=0;line[i]>='A'&&line[i]<='Z';i++) a = 26*a + (line[i] - 'A')+1;
    for(;line[i]!='\0';i++) b = 10*b + (line[i] - '0');
    printf("R%dC%d\n",b,a);
  }
}

int main(int argc, char *argv[]){
  int N; 
  scanf("%d",&N);
  while(N--){
    scanf("%s",line);
    L=strlen(line);
    solve();
  }
  return 0;
}