#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

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
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

#define max_n 1000005


int main(){
  int x[3], y[3];
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b < a) swap(a, b);
    x[i] = a, y[i] = b;
    sum += a * b;
  }
  int n = sqrt(sum);
  if (n * n != sum) {
    printf("-1\n");
    return 0;
  }
  int master = -1;
  if (y[0] == y[1] && y[1] == y[2] && y[2] == n) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int u = 0;
        if (i >= x[0]) u++;
        if (i >= x[0] + x[1]) u++;
        printf("%c",'A'+u);
      }
      printf("\n");
    }
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (y[i] == n) master = i;
  }
  if (master == -1) {
    printf("-1\n");
    return 0;
  }
  bool red_flag = false;
  for (int i = 0; i < 3; i++) {
    if (i != master) {
      if (x[i] != (n - x[master]) && y[i] != (n - x[master])) red_flag = true;
      if (x[i] != (n - x[master])) swap(y[i], x[i]);
    }
  }
  if (red_flag) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", n);
  for (int i = 0; i < x[master]; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", 'A'+master);
    }
    printf("\n");
  }
  int normal1 = -1, normal2 = -1;
  for (int i = 0; i < 3; i++) {
    if (i != master && normal1 != -1) normal2 = i;
    else if (i != master) normal1 = i;
  }
  for (int i = 0; i < n - x[master]; i++) {
    for (int j = 0; j < n; j++) {
      if (j < y[normal1]) printf("%c",'A' + normal1);
      else printf("%c",'A' + normal2);
    }
    printf("\n");
  }



}