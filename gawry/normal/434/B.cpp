#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
struct T {
  bool f[1000][1001];
  int extends[1000][1001];
  void calc(){
    FOR(x,1000)for(int y=999;y>=0;y--)extends[x][y]=f[x][y]?1+extends[x][y+1]:0;
  }
  void flip(int x,int y){
    f[x][y]^=1;
    for(int yy=y;yy>=0;yy--)extends[x][yy]=f[x][yy]?1+extends[x][yy+1]:0;
  }
  int longest(int x,int y){
    vi up,down;
    FOR(xx,x+1)up.push_back(xx);
    for(int xx=999;xx>=x;xx--)down.push_back(xx);
    int ans=0;
//    cout<<extends[x][y]<<" "<<x<<" "<<y<<endl;
    for(int h=1000;h>=1;h--){
      while(up.size()&&extends[up.back()][y]>=h)up.pop_back();
      while(down.size()&&extends[down.back()][y]>=h)down.pop_back();
      ans=max(ans,h*((down.size()?down.back():1000)-(up.size()?up.back():-1)-1));
    }
    return ans;
  }
} a,b,c,d;
int main(){
  int h,w,q;
  scanf("%d %d %d",&h,&w,&q);
  FOR(i,h)FOR(j,w){
    int x;
    scanf("%d",&x);
    if(!x)continue;
    a.f[i][j]^=1;
    b.f[j][i]^=1;
    c.f[i][999-j]^=1;
    d.f[j][999-i]^=1;
  }
  a.calc();
  b.calc();
  c.calc();
  d.calc();
  while(q--){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    --y;--z;
    if(x==1){
      a.flip(y,z);
      b.flip(z,y);
      c.flip(y,999-z);
      d.flip(z,999-y);
    }else{
      printf("%d\n",max(max(a.longest(y,z),c.longest(y,999-z)),max(b.longest(z,y),d.longest(z,999-y))));
    }
  }
  return 0;
}