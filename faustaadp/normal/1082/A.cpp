#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,x,y,d,has,K;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y>>d;
        K=1e18;
        has=K;
        if((abs(y-x))%d==0)
        {
            has=abs(y-x)/d;
        }
        else
        {
            if((y-1)%d==0)has=min(has,(y-1)/d+(x-1)/d+(((x-1)%d)!=0));
            if((n-y)%d==0)has=min(has,(n-y)/d+(n-x)/d+(((n-x)%d)!=0));
        }
        if(has==K)has=-1;
        cout<<has<<"\n";

    }
}