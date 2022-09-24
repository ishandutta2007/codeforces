#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL gcd(LL X,LL Y)
{
    while(Y!=0)
    {
        LL t=Y;
        Y=X%Y;
        X=t;
    }
    return X;
}
LL N,T,ans,A;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T-->0)
    {
        cin>>A;
        N=180/gcd(A,180);
        ans=N;
        while(180-360/ans<A)
            ans+=N;
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}