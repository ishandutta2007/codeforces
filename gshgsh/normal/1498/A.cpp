#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;ll N;ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}ll ask(ll x){ll ans=0;while(x)ans+=x%10,x/=10;return ans;}
int main(){cin>>T;while(T--){cin>>N;while(GCD(N,ask(N))==1)N++;cout<<N<<endl;}return 0;}