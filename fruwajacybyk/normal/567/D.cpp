#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

int n,k,a;

bool check(VI v){
  v.pb(0);
  sort(v.begin(),v.end());
  v.pb(n+1);
  int ile = 0;
  FOR(i,0,v.size()-1){
    int u = (v[i+1]-v[i]-1);
    if(u<a) continue;
    else{
      ile++;
      u-=a; ile += u/(a+1);
    }
  }
  if(ile>=k) return true;
  else return false;
}

VI pref(VI& v,int u){
  VI ans; FOR(i,0,u) ans.pb(v[i]);
  return ans;
}

int main(){
  read3(n,k,a);
  VI mvs;
  make(m);
  FOR(i,0,m){
    make(b);
    mvs.pb(b);
  }
  int left = 0, right = m;
  if(check(pref(mvs,m))){
    printf("-1\n");
    return 0;
  }
  while(right-left>1){
    int mid = (right+left)/2;
    if(check(pref(mvs,mid))) left = mid;
    else right = mid;
  }
  int myns = right;
  if(!check(pref(mvs,left))) myns = left;
  printf("%d\n",max(myns,1));
}