#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,a[MAXN];int main(){cin>>T;while(T--){cin>>N;int id=0;For(i,1,N)cin>>a[i],a[i]&&!id?id=i:0;int cnt=0,tmp=0;For(i,id,N)a[i]?cnt+=tmp,tmp=0:tmp++;cout<<cnt<<endl;}return 0;}