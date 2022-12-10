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
int64 det(int64 x0,int64 y0,int64 x1,int64 y1) {
  int64 tmp=x0*y1-y0*x1;
  return tmp;
}
int64 sgn(int64 tmp){
  return tmp>0?1:tmp<0?-1:0;
}
/* Sprawdzanie czy para odcinkow sie przecina (lacznie z koncami) */
bool intersection(int64 x1,int64 y1,int64 x2,int64 y2,
                  int64 x3,int64 y3,int64 x4,int64 y4) {
  int64 x1p=min(x1,x2),y1p=min(y1,y2),x2p=max(x1,x2),y2p=max(y1,y2);
  int64 x3p=min(x3,x4),y3p=min(y3,y4),x4p=max(x3,x4),y4p=max(y3,y4);

  return x2p>=x3p && x4p>=x1p && y2p>=y3p && y4p>=y1p &&
  sgn(det(x3-x1,y3-y1,x2-x1,y2-y1))*sgn(det(x4-x1,y4-y1,x2-x1,y2-y1))<=0 &&
  sgn(det(x1-x3,y1-y3,x4-x3,y4-y3))*sgn(det(x2-x3,y2-y3,x4-x3,y4-y3))<=0;
}
int n,x[210],y[210],t[210][210];
const int MOD=1000000000+7;
bool ok[210][210];
bool check(int64 x0,int64 y0,int64 x1,int64 y1,int64 x2,int64 y2){
  if(det(x0,y0,x2,y2)>0)return det(x0,y0,x1,y1)>0&&det(x1,y1,x2,y2)>0;
  return det(x2,y2,x1,y1)<0||det(x1,y1,x0,y0)<0;
}
int main(){
  scanf("%d",&n);
  FOR(i,n)scanf("%d %d",&x[i],&y[i]),x[i]*=2,y[i]*=2;
  int64 area=0;
  x[n]=x[0];y[n]=y[0];
  FOR(i,n)area+=det(x[i],y[i],x[i+1],y[i+1]);
  if(area<0){
    reverse(x,x+n+1);
    reverse(y,y+n+1);
  }
  memset(t,0,sizeof(t));
  FOR(i,n)FOR(j,n)if(i!=j&&(i+1)%n!=j&&(j+1)%n!=i){
    ok[i][j]=true;
    FOR(k,n)if(k!=i&&k!=j&&(k+1)%n!=i&&(k+1)%n!=j){
      ok[i][j]&=!intersection(x[i],y[i],x[j],y[j],x[k],y[k],x[k+1],y[k+1]);
    }else{
      int cnt=0;
      cnt+=intersection(x[i],y[i],x[j],y[j],x[k],y[k],x[k],y[k]);
      cnt+=intersection(x[i],y[i],x[j],y[j],x[k+1],y[k+1],x[k+1],y[k+1]);
      cnt+=intersection(x[i],y[i],x[i],y[i],x[k],y[k],x[k+1],y[k+1]);
      cnt+=intersection(x[j],y[j],x[j],y[j],x[k],y[k],x[k+1],y[k+1]);
      ok[i][j]&=cnt<=2;
    }
    if(!ok[i][j])continue;
/*    int tmp_x=(x[i]+x[j])/2,tmp_y=(y[i]+y[j])/2;
    int dx=20000000,dy=dx*M_PI;
    int cnt=0;
    FOR(k,n)cnt+=intersection(tmp_x,tmp_y,tmp_x+dx,tmp_y+dy,x[k],y[k],x[k+1],y[k+1]);
    ok[i][j]&=cnt%2;
    if(!ok[i][j])continue;
    dy+=1337;
    cnt=0;
    FOR(k,n)cnt+=intersection(tmp_x,tmp_y,tmp_x+dx,tmp_y+dy,x[k],y[k],x[k+1],y[k+1]);
    ok[i][j]&=cnt%2;*/
  }
  for(int i=0;i<n;i++){
    t[i][(i+2)%n]=1;
  }
  for(int len=3;len<n;len++)for(int start=0;start<n;start++){
    int64 ans=0;
    bool left[210]={},right[210]={};
    FOR(k,n)left[k]=ok[start][k]&&check(x[start+1]-x[start],y[start+1]-y[start],x[k]-x[start],y[k]-y[start],x[(start+len)%n]-x[start],y[(start+len)%n]-y[start]);
    int tmp=(start+len)%n;
    FOR(k,n)right[k]=ok[k][(start+len)%n]&&check(x[start]-x[tmp],y[start]-y[tmp],x[k]-x[tmp],y[k]-y[tmp],x[(start+len-1)%n]-x[tmp],y[(start+len-1)%n]-y[tmp]);
    if(left[(start+len-1)%n])ans+=t[start][(start+len-1)%n];
    if(right[(start+1)%n])ans+=t[(start+1)%n][(start+len)%n];
    for(int z=(start+1)%n;z!=(start+len)%n;z=(z+1)%n)if(left[z]&&right[z]){
      ans+=(int64)t[start][z]*t[z][(start+len)%n]%MOD;
    }
    t[start][(start+len)%n]=ans%MOD;
  }
  printf("%d\n",t[0][n-1]);
  return 0;
}