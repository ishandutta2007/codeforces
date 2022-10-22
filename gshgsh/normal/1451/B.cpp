#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M;char a[MAXN];
int main(){cin>>T;while(T--){cin>>N>>M;For(i,1,N)cin>>a[i];For(i,1,M){int l,r;cin>>l>>r;bool flag=0;For(j,1,N)if((j<l&&a[j]==a[l])||(j>r&&a[j]==a[r])){cout<<"YES\n";flag=1;break;}if(!flag)cout<<"NO\n";}}return 0;}