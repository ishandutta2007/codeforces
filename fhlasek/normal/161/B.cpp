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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

vector<pair<int,int> > s,p;
bool done[111111];

int main(int argc, char *argv[]){
  int K,N,c,t;
  scanf("%d%d",&N,&K);
  long long ans = 0;
  REP(i,N){
    scanf("%d%d",&c,&t);
    if(t == 1) s.push_back(make_pair(c,i));
    else p.push_back(make_pair(c,i));
    ans += c;
  }
  ans *= 2;
  sort(s.begin(),s.end());
  sort(p.begin(),p.end());
  int S = s.size();
  int P = p.size();
  int rem = N;
  REP(i,min(K-1,S)){ done[s[S-i-1].second] = true; rem--; ans -= s[S-i-1].first; }
  if(S >= K) ans -= min(s[0].first,(P?p[0].first:s[0].first));
  cout << ans/2 << "." << 5*(ans%2)<<endl;
  REP(i,min(K-1,S)) printf("1 %d\n",s[S-i-1].second+1);
  REP(i,K-1-min(K-1,S)){ done[p[i].second] = true; rem--; printf("1 %d\n",p[i].second+1); }
  printf("%d",rem);
  REP(i,N) if(!done[i]) printf(" %d",i+1);
  printf("\n");
  return 0;
}