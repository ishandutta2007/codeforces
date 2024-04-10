#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#define max MAX
#define min MIN
using namespace std;
main(){
  int n,a,b,t;
  scanf("%d %d %d %d",&n,&a,&b,&t);
  char photo[500005];
  scanf("%s",photo);
  int time[500005];
  for(int i=0;i<n;i++)
  {
      if(photo[i]=='h')
        time[i]=1;
      else
        time[i]=1+b;
  }
  for(int i=1;i<n;i++)
  {
      time[i]+=time[i-1];
  }
  int min=0,max=n;
  while(max>min+1){
    int mid=(max+min)/2;
    int ok=0;
    for(int i=1;i<=mid/2-1;i++){
        int sum=time[i]+i*a;
        sum+=a*(mid-1);
        sum+=time[n-1]-time[n-1-(mid-i-1)];
        if(sum<=t){
            ok=1;
            break;
        }
    }
    if(time[mid-1]+(mid-1)*a<=t)
        ok=1;
    for(int i=1;!ok&&i<=mid/2-1;i++){
        int sum=time[n-1]-time[n-1-i]+i*a;
        sum+=a*(mid-1);
        sum+=time[mid-i-1];
        if(sum<=t){
            ok=1;
            break;
        }
    }
    if(time[n-1]-time[n-1-mid+1]+time[0]+a*(mid-1)<=t)
        ok=1;
    if(ok)
        min=mid;
    else
        max=mid;
  }
  int mid=max;
  int ok=0;
    for(int i=1;i<=mid/2-1;i++){
        int sum=time[i]+i*a;
        sum+=a*(mid-1);
        sum+=time[n-1]-time[n-1-(mid-i-1)];
        if(sum<=t){
            ok=1;
            break;
        }
    }
    if(time[mid-1]+(mid-1)*a<=t)
        ok=1;
    for(int i=1;!ok&&i<=mid/2-1;i++){
        int sum=time[n-1]-time[n-1-i]+i*a;
        sum+=a*(mid-1);
        sum+=time[mid-i-1];
        if(sum<=t){
            ok=1;
            break;
        }
    }
    if(time[n-1]-time[n-1-mid+1]+time[0]+a*(mid-1)<=t)
        ok=1;
  if(ok)
  printf("%d\n",max);
  else
    printf("%d\n",min);
}