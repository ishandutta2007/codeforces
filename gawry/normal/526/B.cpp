#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int MAX=1<<15;
int n,t[MAX],r[MAX];
long long ans;
void go(int pos,int cur){
  if(pos<(1<<n)){
//    printf("%d %d : %d %d\n",pos,cur,r[pos*2],r[pos*2+1]);
    ans+=cur-r[pos*2]-t[pos*2];
    ans+=cur-r[pos*2+1]-t[pos*2+1];
    go(2*pos,r[pos*2]);
    go(2*pos+1,r[pos*2+1]);
  }else{
  }
}
int main(){
  scanf("%d",&n);
  for(int i=2;i<(1<<(n+1));i++){
    scanf("%d",&t[i]);
  }
  for(int i=(1<<(n+1))-1;i>1;i--){
    r[i/2]=max(r[i/2],r[i]+t[i]);
  }
//  printf("%d\n",r[1]);
  ans=0;
  go(1,r[1]);
  cout<<ans<<endl;
  return 0;
}