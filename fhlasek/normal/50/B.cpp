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
#define MAXN 100111

using namespace std;

int c[257];
char line[MAXN];

int main(int argc, char *argv[]){
  long long res=0;
  int i;
  scanf("%s",line);
  for(i=0;line[i]!='\0';i++) c[line[i]+128]++;
  FOR(i,257) res+=(long long)c[i]*c[i];
  printf("%lld\n",res);
  return 0;
}