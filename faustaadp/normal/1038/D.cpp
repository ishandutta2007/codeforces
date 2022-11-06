#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[501010],NEG,SU,has;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cin>>n;
        cout<<n<<"\n";
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            NEG++;
        a[i]=abs(a[i]);
        SU+=a[i];
    }
    sort(a+1,a+1+n);
    if(NEG>0&&NEG<n)
    {
        has=SU;
    }
    else
    {
        has=SU-a[1]*2;
    }
    cout<<has<<"\n";
}