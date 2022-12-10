#include<iostream>
#include<cassert>
using namespace std;
long long mem[80][80];
long long f(int level,long long height,int cnt){
  assert(height<=(1LL<<level));
  if(height<1)return 0;
  if(!level)return !cnt;
  long long prev=1LL<<level-1;
  if(height<=prev)return f(level-1,height,cnt);
  return mem[level-1][cnt]+(cnt?f(level-1,height-prev,cnt-1):0);
}
long long n,t;
main(){
  mem[0][0]=1;
  for(int level=1;level<=60;level++){
    for(int cnt=0;cnt<=60;cnt++)mem[level][cnt]+=mem[level-1][cnt];
    for(int cnt=0;cnt<=60;cnt++)mem[level][cnt+1]+=mem[level-1][cnt];
  }
  cin>>n>>t;
  int p=0;
  while((1LL<<p)<t)++p;
  if((1LL<<p)!=t){
    cout<<0<<endl;
    return 0;
  }
  long long ans=0;
  ++n;
  for(int level=1;level<=60;level++){
    long long start=(1LL<<level);
    if(start>n)break;
    ans+=f(level,min(n-start+1,1LL<<level),p);
  }
  cout<<ans<<endl;
}