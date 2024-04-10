#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long det(long long a,long long b,long long c,long long d){
  return a*d-b*c;
}
const int ZERO=1100000;
int n,x[100001],y[100001],from[2*ZERO],to[2*ZERO];
double calc(){
  long long area=0;
  x[n]=x[0];
  y[n]=y[0];
  for(int i=0;i<n;i++)area+=det(x[i],y[i],x[i+1],y[i+1]);
  if(area>0){
    reverse(x,x+n);
    reverse(y,y+n);
    x[n]=x[0];
    y[n]=y[0];
  }
//for(int i=0;i<n;i++)printf("%d,%d\n",x[i],y[i]);
  int min_x=2*ZERO,max_x=0;
  for(int i=0;i<n;i++){
    min_x=min(min_x,x[i]);
    max_x=max(max_x,x[i]);
  }
  for(int i=0;i<n;i++)if(x[i]<x[i+1]){
    for(int tx=x[i];tx<=x[i+1];tx++){
      int ty=((long long)y[i+1]*(tx-x[i])+(long long)y[i]*(x[i+1]-tx))/(x[i+1]-x[i]);
      to[tx]=ty;
    }
  }else if(x[i]>x[i+1]){
    for(int tx=x[i+1];tx<=x[i];tx++){
      int ty=((long long)y[i]*(tx-x[i+1])+(long long)y[i+1]*(x[i]-tx)+x[i]-x[i+1]-1)/(x[i]-x[i+1]);
      from[tx]=ty;
    }
  }else{
    from[x[i]]=min(y[i],y[i+1]);
    to[x[i]]=max(y[i],y[i+1]);
  }
  long double ans=0,sum=0,sum_square=0,cnt=0;
  for(int tx=min_x;tx<=max_x;tx++){
    int cur_cnt=to[tx]-from[tx]+1;
    
    ans+=(long double)cur_cnt*cnt*tx*tx;
    ans+=(long double)cur_cnt*sum_square;
    ans-=(long double)2*cur_cnt*tx*sum;
    
    sum+=(long double)cur_cnt*tx;
    sum_square+=(long double)cur_cnt*tx*tx;
    cnt+=cur_cnt;
  }
  //cout<<cnt<<endl;
  return ans*2/cnt/(cnt-1);
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&x[i],&y[i]);
    x[i]+=ZERO;
    y[i]+=ZERO;
  }
  double ans=calc();
  for(int i=0;i<n;i++)swap(x[i],y[i]);
  ans+=calc();
  
  printf("%.6lf\n",ans/2);
}