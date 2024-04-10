#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);int ans=N-1;For(i,2,N)if(a[i]==a[1])ans--;cout<<ans<<endl;}return 0;}