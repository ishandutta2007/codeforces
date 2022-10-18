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
#define MAXN 1001

using namespace std;

int seq[MAXN][4];
char line[5];

int main(int argc, char *argv[]){
  int N,i,res=0,j;
  bool ok;
  scanf("%d",&N);
  FOR(i,N){
    if(i) scanf("%s",line);
    scanf("%s",line);
    seq[i][0]=line[0]-'0';
    seq[i][1]=line[1]-'0';
    scanf("%s",line);
    seq[i][2]=line[0]-'0';
    seq[i][3]=line[1]-'0';
    ok=false;
    FOR(j,i){
      if((seq[i][0]==seq[j][0]&&seq[i][1]==seq[j][1]&&seq[i][2]==seq[j][2]&&seq[i][3]==seq[j][3])||
         (seq[i][0]==seq[j][2]&&seq[i][1]==seq[j][0]&&seq[i][2]==seq[j][3]&&seq[i][3]==seq[j][1])||
         (seq[i][0]==seq[j][3]&&seq[i][1]==seq[j][2]&&seq[i][2]==seq[j][1]&&seq[i][3]==seq[j][0])||
         (seq[i][0]==seq[j][1]&&seq[i][1]==seq[j][3]&&seq[i][2]==seq[j][0]&&seq[i][3]==seq[j][2])){
        ok=true;
        break;
      }
    }
    if(!ok) res++;
  }
  printf("%d\n",res);
  
  return 0;
}