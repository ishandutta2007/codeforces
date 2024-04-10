#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int T,N;int main(){cin>>T;while(T--){cin>>N;bool flag=0;map<int,int>cnt;int x;while(N--)cin>>x,flag|=cnt[x],cnt[x]=1;cout<<(flag?"YES\n":"NO\n");}return 0;}