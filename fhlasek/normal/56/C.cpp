#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 1001

using namespace std;

string p[MAXN];
int P,S,pos;
char line[MAXN+1];

void check(){
  int i;
  FOR(i,P-1){ if(p[i]==p[P-1]) S++; }
}

void employee(){
  string s="";
  for(;'A'<=line[pos]&&line[pos]<='Z';pos++) s.push_back(line[pos]);
  p[P++]=s;
  check();
  while(line[pos++]!='.') employee();
  P--;
}

int main(int argc, char *argv[]){
  P=0; S=0;
  pos=0;
  scanf("%s",line);
  employee();
  printf("%d\n",S);   
  return 0;
}