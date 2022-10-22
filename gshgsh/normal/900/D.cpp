#include<iostream>
#include<map>
using namespace std;
#define P 1000000007
int x,y;map<int,int>f;int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int sol(int x){if(x==1)return 1;if(f[x])return f[x];int ans=0;for(int i=2;i*i<=x;i++)if(x%i==0)ans=(ans+sol(i))%P,i*i!=x?ans=(ans+sol(x/i))%P:0;return f[x]=(pow(2,x-1)-1-ans+P)%P;}
int main(){cin>>x>>y;if(y%x){cout<<0<<endl;return 0;}cout<<sol(y/x)<<endl;return 0;}