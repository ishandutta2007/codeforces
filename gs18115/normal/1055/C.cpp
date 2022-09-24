#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
LL l,r,t,L,R,T,p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>l>>r>>t;
    cin>>L>>R>>T;
    if(l==0&&r==t-1)
        return cout<<R-L+1<<endl,0;
    if(L==0&&R==T-1)
        return cout<<r-l+1<<endl,0;
    p=gcd(t,T);
    LL maxi=-1;
    for(LL i=-5;i<=5;i++)
        maxi=max(maxi,min(R+((l-L)/p+i)*p,r)-max(L+((l-L)/p+i)*p,l));
    cout<<maxi+1<<endl;
    return 0;
}