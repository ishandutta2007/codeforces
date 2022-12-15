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
#define max_n 200005

char s1[max_n],s2[max_n];
int n;
int mod = 1e9+9;

VI hash[2];

void rob(char* s, int n, int b,int ind){
  FOR(i,0,n/b){
    int mask = 0;
    FOR(j,b*i,b*i+b){
      mask = (mask *311LL)%mod;
      mask += (s[j]-'a');
      mask %= mod;
    }
    hash[ind].pb(mask);
  }
}

void quasisort(int a,int b, int ind){
  if(a==b || b==(a+1)) return;
  int mid = (a+b)/2;
  quasisort(a,mid,ind);
  quasisort(mid,b,ind);
  bool ok = true;
  FOR(i,a,mid){
    if(hash[ind][i] < hash[ind][mid+i-a]) break;
    if(hash[ind][i] > hash[ind][mid+i-a]){
      ok = false;
      break;
    }
  }
  if(!ok){
    FOR(i,a,mid){
     
      swap(hash[ind][i],hash[ind][mid+i-a]);
    }
  }
}


int main(){
  scanf("%s",s1);
  scanf("%s",s2);
  n = strlen(s1);
  int b = n; while(b%2==0) b = b/2;
  rob(s1,n,b,0);
  rob(s2,n,b,1);
  quasisort(0,n/b,0);
  quasisort(0,n/b,1);
  bool ans = true;
  FOR(i,0,n/b) if(hash[0][i]!=hash[1][i]) ans = false;
  if(ans) printf("YES\n");
  else printf("NO\n");
  

}