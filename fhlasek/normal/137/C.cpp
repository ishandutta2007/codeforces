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

vector<pair<int,int> > v;

int main(int argc, char *argv[]){
  int N,a,b,last = -1,res=0;
  scanf("%d",&N);
  REP(i,N){ scanf("%d%d",&a,&b); v.push_back(make_pair(a,b)); }
  sort(v.begin(),v.end());
  REP(i,N){
    if(v[i].second<last) res++; 
    last = max(last,v[i].second);
  }
  printf("%d\n",res);
  return 0;
}