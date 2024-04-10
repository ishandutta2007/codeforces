#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],pos[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i],pos[a[i]]=i;int now=N;FOR(i,N,1)if(pos[i]){int tmp=pos[i];For(j,pos[i],now)cout<<a[j]<<' ',pos[a[j]]=0;now=tmp-1;}cout<<endl;}return 0;}