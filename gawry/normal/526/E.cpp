#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int MAX=1100000;
int n,q,level[MAX],last[MAX],jumps[MAX];
long long b;
long long after[MAX];
int main(){
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++)scanf("%d",&level[i]);
  after[n]=0;
  for(int i=n-1;i>=0;i--)after[i]=after[i+1]+level[i];
  while(q--){
    cin>>b;
    long long sum=0;
    last[n]=n;
    jumps[n]=0;
    for(int i=n-1,j=n-1;i>=0;i--){
      sum+=level[i];
      while(sum>b){
        sum-=level[j];
        --j;
      }
      if(j<n-1){
        last[i]=last[j+1];
        jumps[i]=1+jumps[j+1];
      }else{
        last[i]=i;
        jumps[i]=0;
      }
    }
    //for(int i=0;i<n;i++)printf("%d: %d +%d\n",i,last[i],jumps[i]);
    sum=0;
    int ans=n;
    if(after[0]<=b)ans=1;
    for(int i=0;i<n;i++){
      int j=last[i];
      long long suffix=after[j];
      long long prefix=after[0]-after[i];
      int total=jumps[i]+(suffix+prefix<=b?1:2);
      //cout<<i<<" "<<prefix<<" "<<suffix<<" "<<total<<endl;
      ans=min(ans,total);
      sum+=level[i];
      if(sum>b)break;
    }
    printf("%d\n",ans);
  }
  return 0;
}