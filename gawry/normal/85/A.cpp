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

int n;
char t[4][110];
int get(int x,int y){return x>=0&&y>=0?t[x][y]:0;}
void add(int x0,int y0,int x1,int y1){
  int m=0;
  set<char> b;
  int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
  for(int k=0;k<4;k++){
    b.insert(get(x0+dx[k],y0+dy[k]));
    b.insert(get(x0+dx[k],y0+dy[k]));
    b.insert(get(x1+dx[k],y1+dy[k]));
    b.insert(get(x1+dx[k],y1+dy[k]));
  }
  char r='a';
  while(b.count(r))r++;
  t[x0][y0]=t[x1][y1]=r;
}
main() {
  scanf("%d",&n);
  if(n%2==0){
    for(int i=0;i<n;i+=2)add(0,i,0,i+1),add(3,i,3,i+1);
    add(1,0,2,0);
    add(1,n-1,2,n-1);
    for(int i=1;i+1<n;i+=2)add(1,i,1,i+1),add(2,i,2,i+1);
  }else{
    for(int i=0;i+1<n;i+=2)add(0,i,0,i+1),add(1,i,1,i+1),add(2,i+1,2,i+2),add(3,i+1,3,i+2);
    add(0,n-1,1,n-1);
    add(2,0,3,0);
  }
  for(int i=0;i<4;i++)puts(t[i]);
}