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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222
char song[MAXN];
int N;

int main(int argc, char *argv[]){
  scanf("%s",song);
  N = strlen(song);
  REP(i, N) REP(j, N - 2) if(song[j] == 'W' && song[j+1] == 'U' && song[j+2] == 'B'){
    song[j] = song[j + 1] = song[j + 2] = ' ';
  }
  bool space = true;
  REP(i,N){
    if(song[i] == ' '){
      if(!space){
        printf(" ");
        space = true;
      }
    }
    else{
      printf("%c", song[i]);
      space = false;
    }
  }
  printf("\n");
  return 0;
}