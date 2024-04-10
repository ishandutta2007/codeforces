#include<iostream>
using namespace std;
typedef long long LL;
LL T,N,M,K;
LL ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>N>>M>>K;
        if(N>K||M>K)
            ans=-1LL;
        else
        {
            if(((N+M)&1LL)==1LL)
                ans=K-1LL;
            else if(((N+K)&1LL)==1LL)
                ans=K-2LL;
            else
                ans=K;
        }
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}