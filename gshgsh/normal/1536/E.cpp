#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
int T,N,M;int get(){char c=getchar();while(c!='0'&&c!='#')c=getchar();return c=='#';}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main(){cin>>T;while(T--){cin>>N>>M;int cnt=0;For(i,1,N*M)cnt+=get();cout<<pow(2,cnt)-(cnt==N*M)<<endl;}return 0;}