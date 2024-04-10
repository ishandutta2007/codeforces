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

int a,b;
set<int> s;

void test(int x){ if(b%x==0) s.insert(x); }

int main(int argc, char *argv[]){
  scanf("%d%d",&a,&b);
  int i,N,l,h;
  for(i=1;i*i<=a;i++) if(a%i==0){ test(i); test(a/i); } 
  scanf("%d",&N);
  set<int>::iterator it;
  FOR(i,N){
    scanf("%d%d",&l,&h);
    it=s.upper_bound(h);
    if(it==s.begin()){ printf("-1\n"); continue; }
    it=--it;
    if((*it)<l) printf("-1\n");
    else printf("%d\n",(*it));
  }
  return 0;
}