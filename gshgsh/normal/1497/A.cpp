#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],cnt[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,0,100)cnt[i]=0;For(i,1,N)cin>>a[i],cnt[a[i]]++;For(i,0,100)if(cnt[i])cout<<i<<' ',cnt[i]--;For(i,0,100)while(cnt[i])cout<<i<<' ',cnt[i]--;cout<<endl;}return 0;}