#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[50],p;
long double t[60][60][60],tt[60][60][60],f[60];
main(){
  f[0]=1.0;
  for(int i=1;i<60;i++)f[i]=f[i-1]*i;
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  scanf("%d",&p);
  t[0][0][0]=1;
  for(int i=0;i<n;i++){
    memcpy(tt,t,sizeof(tt));
    for(int sum=0;sum<=p;sum++)for(int cnt=0;cnt<=i;cnt++)for(int next=0;next<=50;next++){
      if(sum+a[i]<=p)tt[sum+a[i]][cnt+1][next]+=t[sum][cnt][next];
      if(!next)tt[sum][cnt][a[i]]+=t[sum][cnt][next];
    }
    memcpy(t,tt,sizeof(t));
  }
  long double ans=0.0;
  int all=0;
  for(int i=0;i<n;i++)all+=a[i];
  if(all<=p)ans=n;
  for(int sum=0;sum<=p;sum++)for(int cnt=0;cnt<=n;cnt++)for(int next=1;next<=50;next++)if(sum+next>p){
    ans+=cnt*t[sum][cnt][next]*f[cnt]*f[n-1-cnt]/f[n];
  }
  printf("%.6lf\n",(double)ans);
}