#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,K,a[MAXN];
int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);cout<<(a[1]+a[2]<=K||a[N]<=K?"YES\n":"NO\n");}return 0;}