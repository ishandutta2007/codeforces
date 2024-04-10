#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 400001
int T,N,a[MAXN];int main(){cin>>T;while(T--){cin>>N;int mx=0;For(i,1,N)cin>>a[i],mx=max(mx,a[i]);a[0]=a[N+1]=mx+1;bool flag=0;For(i,1,N)if(a[i]==mx&&(a[i]>a[i-1]||a[i]>a[i+1])){cout<<i<<endl;flag=1;break;}if(!flag)cout<<-1<<endl;}return 0;}