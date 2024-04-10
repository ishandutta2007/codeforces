#include<iostream>
using namespace std;
#define ll long long
#define P 1000000007
#define inv2 500000004
ll N,M,ans;int main(){cin>>N>>M;ans=N%P*(M%P)%P,M=min(M,N);for(ll l=1,r;l<=M;l=r+1)r=min(M,N/(N/l)),ans=(ans-(r-l+1)%P*((l+r)%P)%P*inv2%P*(N/l%P)%P+P)%P;cout<<ans<<endl;return 0;}