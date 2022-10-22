#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,M;int main(){cin>>T;while(T--){cin>>N>>M;For(i,1,N){For(j,1,M){int x;cin>>x;x+=((i+j&1)&&(x&1))||(((i+j&1)^1)&&((x&1)^1));cout<<x<<' ';}cout<<endl;}}return 0;}