#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;ll N;int getans(ll x){int ans=0;while(x)ans+=x%10,x/=10;return ans;}
int main(){cin>>T;while(T--)cin>>N,cout<<(N%2050?-1:getans(N/2050))<<endl;return 0;}