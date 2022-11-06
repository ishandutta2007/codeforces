#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,tem,haz,itu,hv,j,a[10101010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    haz=1e18;
    for(i=1;i<=n;i++)
    {
        tem=n/i+n%i+i;
        if(tem<haz)
        {
            haz=tem;
            itu=i;
       //     itu2=n/i+n%i;
        }
    }
    hv=n;
    //cout<<itu<<" "<<n/itu+n%itu<<"\n";
    //return 0;
    itu=sqrt(n);
    ll  boleh=1;
    i=0;
    while(boleh)
    {
        i+=itu;
        //cout<<i<<"\n";
        if(i>=n)
            boleh=0;
        i=min(n,i);
        a[i]=hv;
        hv-=itu;
        for(j=i-1;j>i-itu;j--)
        {
            if(a[j]>0)
            {
                i=n+1;
                boleh=0;
                break;
            }
            //cout<<"A"<<j<<"\n";
            a[j]=a[j+1]-1;
        }
    }
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
}