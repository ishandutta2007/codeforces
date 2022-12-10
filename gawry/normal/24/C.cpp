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

#define MAX 110000
int n,x[MAX],y[MAX];
int64 sx,sy,t;
main() {
  cin>>n>>t>>sx>>sy;
  --t;
  FOR(i,n)scanf("%d %d",&x[i],&y[i]);
  t%=2*n;
  FOR(i,t+1){
    sx=2*x[i%n]-sx;
    sy=2*y[i%n]-sy;
  }
  cout<<sx<<" "<<sy<<endl;
}