#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 3001
int T,N,a[MAXN];int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i];int tmp=0,ans=N-1;For(i,1,N){tmp+=a[i];int sum=0,cnt=1;bool flag=1;For(j,i+1,N){sum+=a[j];if(sum>tmp){flag=0;break;}if(sum==tmp)sum=0,cnt++;}if(flag&&(sum==0||sum==tmp))ans=min(ans,N-cnt);}cout<<ans<<endl;}return 0;}