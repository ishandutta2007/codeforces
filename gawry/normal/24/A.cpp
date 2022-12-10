#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<queue>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int n,a[110],b[110],c[110],d[110][110];
vi s[110];
main() {
  scanf("%d",&n);
  FOR(i,n){
    scanf("%d %d %d",&a[i],&b[i],&c[i]);
    d[a[i]][b[i]]=c[i];
    d[b[i]][a[i]]=-c[i];
  }
  vi t;
  t.push_back(a[0]);
  t.push_back(b[0]);
  while(t.size()<n){
    int next=0;
    while(next==t[t.size()-2]||!d[t.back()][next])next++;
    t.push_back(next);
  }
//  FOR(i,t.size())cout<<t[i]<<" ";cout<<endl;
  t.push_back(t[0]);
  int x=0,y=0;
  FOR(i,n)x+=max(0,d[t[i]][t[i+1]]),y+=max(0,d[t[i+1]][t[i]]);
  printf("%d\n",min(x,y));
}