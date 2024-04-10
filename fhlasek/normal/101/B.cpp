/* Writen by Filip Hlasek 2011 */
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

#define FOR(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
#define L long long
#define MAXN 131072

using namespace std;

pair<int,int> b[MAXN];
set<int> s;
set<int>::iterator si;
vector<int> v;
map<int,int> m;
int V,t[2*MAXN];

void add(int x,int a){
//  printf("add:%d %d\n",x,a);
  while(x<2*MAXN){
    t[x]=(t[x]+a)%MOD;
    x+=x&-x;
  }
}

int get(int x){
  int sum=0;
  while(x){
    sum=(sum+t[x])%MOD;
    x-=x&-x;
  }
  return sum;
}

int g(int a,int b){
  return (get(b)-get(a)+MOD)%MOD;
}

bool mycompare(pair<int,int> x,pair<int,int> y){ return x.second<y.second; }

int main(int argc, char *argv[]){
  int N,M,i,tmp;
  scanf("%d%d",&N,&M);
  FOR(i,M) scanf("%d%d",&(b[i].first),&(b[i].second));
  sort(b,b+M,mycompare);
  FOR(i,M){ s.insert(b[i].first); s.insert(b[i].second); }
  s.insert(0);
  s.insert(N);
  for(si=s.begin();si!=s.end();++si) v.push_back(*si);
  V=v.size();
  FOR(i,V) m[v[i]]=i+1;
  add(1,1);
  FOR(i,M) add(m[b[i].second],g(m[b[i].first]-1,m[b[i].second]-1));
  printf("%d\n",g(V-1,V));
  return 0;
}