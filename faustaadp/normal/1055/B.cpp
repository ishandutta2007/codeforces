#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,k,a[101010],b[101010],ta,tb,has,i;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)if(a[i]>k)b[i]=1;
    for(i=1;i<=n;i++)if(b[i]==1&&b[i-1]==0)has++;
    while(q--)
    {
        cin>>ta;
        if(ta==1)
        {
            cin>>ta>>tb;
            a[ta]+=tb;
            if(a[ta]>k&&b[ta]==0)
            {
                if(b[ta-1]==1&&b[ta+1]==1)has--;
                if(b[ta-1]==0&&b[ta+1]==0)has++;
                b[ta]=1;
            }
        }
        else
            cout<<has<<"\n";
    }
}