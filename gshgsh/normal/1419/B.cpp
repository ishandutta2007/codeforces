#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;ll N;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;int ans=0;ll now=1;while(1)if(1ll*now*(now+1)/2<=N)N-=1ll*now*(now+1)/2,ans++,now<<=1,now|=1;else break;
        cout<<ans<<endl;
    }
    return 0;
}