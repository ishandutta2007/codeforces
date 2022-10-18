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

vector<int> p;
bool ok(int x){
  sort(p.begin(),p.end());
  int y,sum=0,j;
  FOR(j,24){
    y=x;
    y=(((y%p[0])%p[1])%p[2])%p[3];
    if(y==x) sum++;
    next_permutation(p.begin(),p.end());
  }
  return sum>=7;
}

int main(int argc, char *argv[]){
  int px,x;
  int i,j,a,b,res=0;
  FOR(i,4){ scanf("%d",&px); p.push_back(px); }
  scanf("%d%d",&a,&b);
  for(i=a;i<=b;i++) if(ok(i)) res++;
  printf("%d\n",res);
  return 0;
}