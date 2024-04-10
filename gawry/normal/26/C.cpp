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
#include<cstring>
#include<cassert>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int n,m,a,b,c;
char t[110][110];
void mark(int x,int y,int dx,int dy){
  bool seen[300]={};
  FOR(i,dx)FOR(j,dy){
    int xx=x+i,yy=y+j;
    if(xx)seen[t[xx-1][yy]]=1; 
    if(yy)seen[t[xx][yy-1]]=1; 
    seen[t[xx+1][yy]]=1; 
    seen[t[xx][yy+1]]=1; 
  }
  char next='a';
  while(seen[next])next++;
  FOR(i,dx)FOR(j,dy)t[x+i][y+j]=next; 
}
main() {
  cin>>n>>m>>a>>b>>c;
  int nn=n-n%2,mm=m-m%2;
  if(n%2&&m%2)goto fail;
  if(n%2){
    if(a<m/2)goto fail;
    a-=m/2;
    for(int i=0;i<m;i+=2)mark(n-1,i,1,2);    
  }
  if(m%2){
    if(b<n/2)goto fail;
    b-=n/2;
    for(int i=0;i<n;i+=2)mark(i,m-1,2,1); 
  }
  a-=a%2;
  b-=b%2;
  if(a/2+b/2+c<nn/2*mm/2)goto fail;
  for(int i=0;i<nn;i+=2)for(int j=0;j<mm;j+=2){
    if(a){
      mark(i,j,1,2);
      mark(i+1,j,1,2);
      a-=2;
    }else if(b){
      mark(i,j,2,1);
      mark(i,j+1,2,1);
      b-=2;
    }else if(c){
      mark(i,j,2,2);
      --c;
    }else assert(0); 
  }
  FOR(i,n)puts(t[i]);
  return 0;
fail:
  cout<<"IMPOSSIBLE"<<endl;
}