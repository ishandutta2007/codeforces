#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffff
int T,N,M;int main(){cin>>T;while(T--){cin>>N>>M;int sum1=0,sum2=0,cnt=0,mn=INF;For(i,1,N*M){int x;cin>>x;cnt+=x<=0;(x<=0?sum1:sum2)+=x;mn=min(mn,abs(x));}cout<<sum2-sum1-2*(cnt&1)*mn<<endl;}return 0;}