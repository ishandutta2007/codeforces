#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],A1,Z1,A2,Z2,A,B;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    A1=1;
    Z1=n;
    A2=1;
    Z2=n;
    for(i=1;i<=n;i++)
    {
        if(A2>Z2||b[Z2]<a[Z1])
        {
            A+=a[Z1];
            Z1--;
        }
        else
            Z2--;
        if(A1>Z1||a[Z1]<b[Z2])
        {
            B+=b[Z2];
            Z2--;
        }
        else
            Z1--;
    }
    cout<<A-B<<"\n";
}