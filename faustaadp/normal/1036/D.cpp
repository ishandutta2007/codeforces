#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,has,i,a[303030],b[303030],p1,p2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(i=1;i<=m;i++)
        cin>>b[i];
    p1=1;
    p2=1;
    while(p1<=n&&p2<=m)
    {
        if(a[p1]==b[p2])
        {
            has++;
            p1++;
            p2++;
        }
        else
        if(a[p1]<b[p2])
        {
            a[p1+1]+=a[p1];
            p1++;
        }
        else
        {
            b[p2+1]+=b[p2];
            p2++;
        }
    //    cout<<p1<<" "<<p2<<"\n";
    }
   // cout<<p1<<" "<<p2<<"\n";
    if(p1<=n||p2<=m)
        has=-1;
    cout<<has<<"\n";
}