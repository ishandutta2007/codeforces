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

char line[222];

int main(int argc, char *argv[]){
  scanf("%s",line); 
  int N = strlen(line),res=0,i=0,j;
  while(i<N){
    res++;
    for(j=0;j<5&&i+j<N&&line[i+j]==line[i];j++);
    i+=j;
  }
  printf("%d\n",res);
  return 0;
}