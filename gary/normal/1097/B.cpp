#include<iostream>
using namespace std;
int n,a[20],flag=0,degree=0;
void dfs(int now ){
if(flag) return;
   if(now ==n+1){
if(degree %360==0){
flag =1;
}
return;
}
degree +=a[now];
dfs(now+1);
degree-=2*a[now];
dfs(now+1);
degree+=a[now];
}
int main(){
     cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
  if(flag) cout<<"YES";
  else cout<<"NO";
     return 0;
}