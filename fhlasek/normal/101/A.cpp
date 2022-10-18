/* Writen by Filip Hlasek 2011 */
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
#define MAXN 111111

using namespace std;

char s[MAXN];
pair<int,char> n[30];
bool print[30];

int main(int argc, char *argv[]){
  scanf("%s",s); 
  int i,k;
  FOR(i,26) n[i]=make_pair(0,i);
  for(i=0;s[i]!='\0';i++) n[s[i]-'a'].first++;
  sort(n,n+26);
  scanf("%d",&k);
  for(i=0;i<26&&k>=n[i].first;i++){ k-=n[i].first; print[n[i].second]=true; }
  printf("%d\n",26-i);
  for(i=0;s[i]!='\0';i++) if(!print[s[i]-'a']) printf("%c",s[i]);
  printf("\n");
  return 0;
}