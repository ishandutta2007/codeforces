#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
int T,N;ll K;ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
int main(){cin>>T;while(T--){cin>>N>>K;ll x,y;cin>>x>>y,y=abs(y-x);K=abs(K-x);For(i,3,N){ll a;cin>>a;y=GCD(y,abs(a-x));}cout<<(K%y==0?"YES\n":"NO\n");}return 0;}