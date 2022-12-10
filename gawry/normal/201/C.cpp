#include<cstdio>
#include<iostream>
using namespace std;
int n,t[100000];
long long before[100000],after[100000],ans;
void go(int begin,int end){
  if(begin+1==end){
    ans=max(ans,before[begin]+after[begin]);
    return;
  }
  int middle=(begin+end)/2;
  go(begin,middle);
  go(middle,end);
  long long left=0,right=0,left_sum=0,right_sum=0;
  for(int i=middle;i<end;i++){
    right=max(right,right_sum+after[i]);
    right_sum+=(t[i]-1)/2*2+1;
  }
  for(int i=middle;i>=begin;i--){
    left=max(left,left_sum+before[i]);
    if(i>begin)left_sum+=(t[i-1]-1)/2*2+1;
  }
  ans=max(ans,left+right);
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n-1;i++)scanf("%d",&t[i]);
  before[0]=0;
  for(int i=0;i<n-1;i++){
    before[i+1]=t[i]>1?before[i]+t[i]/2*2:0;
  }
  after[n-1]=0;
  for(int i=n-2;i>=0;i--){
    after[i]=t[i]>1?after[i+1]+t[i]/2*2:0;
  }
/*  for(int i=0;i<n;i++){
    cout<<before[i]<<" "<<after[i]<<endl;
  }*/
  ans=0;
  go(0,n);
  cout<<ans<<endl;
}