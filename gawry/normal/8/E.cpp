#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int64;
int n,p[60];
int64 calc(){
  int64 r=0,add;
  if(p[0]==1)return 0;
  p[0]=0;
  if(p[n-1]!=1){
  // 011111 0       1 1111110
    for(int i=1;i<n/2;i++){
      add=1;
      for(int j=0;j<i;j++){
        if(p[j]>-1&&p[n-1-j]>-1&&p[j]!=p[n-1-j])add=0;
        if(p[j]==-1&&p[n-1-j]==-1)add*=2;
      }
      if(p[i]==1||p[n-1-i]==0)add=0;
      for(int j=i+1;j<(n+1)/2;j++){
        if(p[j]==-1)add*=2;
        if(j<n-1-j&&p[n-1-j]==-1)add*=2; 
      }
      r+=add;
    }
    add=1;
    for(int j=0;j<(n+1)/2;j++){
      if(p[j]>-1&&p[n-1-j]>-1&&p[j]!=p[n-1-j])add=0;
      if(p[j]==-1&&p[n-1-j]==-1)add*=2;    
    }
    r+=add;
  }
  if(p[n-1]!=0){
  // 011111 0       0 0000001
    for(int i=1;i<(n+1)/2;i++){
      add=1;
      for(int j=0;j<i;j++){
        if(p[j]>-1&&p[n-1-j]>-1&&p[j]==p[n-1-j])add=0;
        if(p[j]==-1&&p[n-1-j]==-1)add*=2;
      }
      if(p[i]==1||p[n-1-i]==1)add=0;
      for(int j=i+1;j<(n+1)/2;j++){
        if(p[j]==-1)add*=2;
        if(j<n-1-j&&p[n-1-j]==-1)add*=2; 
      }
      r+=add;
    }
    if(n%2==0){
      add=1;
      for(int j=0;j<n/2;j++){
        if(p[j]>-1&&p[n-1-j]>-1&&p[j]==p[n-1-j])add=0;
        if(p[j]==-1&&p[n-1-j]==-1)add*=2;
      }
      r+=add;  
    }
  }
  return r;
}
int64 cnt(int64 b){
  int d[60]={};
  for(int i=0;i<n;i++)d[i]=b&1LL<<n-1-i?1:0;
  int64 r=0;
  for(int i=0;i<n;i++)if(d[i]){
    for(int j=0;j<n;j++)p[j]=j<i?d[j]:-1;
    p[i]=0;
    r+=calc();
  }
  for(int i=0;i<n;i++)p[i]=d[i];
  r+=calc();
  return r;
}
main(){
  int64 k=0,from,to;
  
  cin>>n>>k;
//  k++;
  from=0,to=1LL<<n;
  if(cnt(to-1)<=k){cout<<-1<<endl;return 0;}
  while(from+1<to){
    int64 middle=(from+to)/2;
    if(cnt(middle)>=k+1)to=middle;else from=middle;
  }
  for(int i=n-1;i>=0;i--)cout<<((to&1LL<<i)?1:0);cout<<endl;
}