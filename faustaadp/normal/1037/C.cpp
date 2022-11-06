#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,has;
char a[1010101],b[1010101];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
    {
        if(i<n&&(a[i]!=b[i])&&(a[i+1]!=b[i+1])&&(a[i]!=a[i+1])&&(b[i]!=b[i+1]))
        {
            has++;
            i++;
        }
        else
        if(a[i]!=b[i])
            has++;
    }
    cout<<has<<"\n";
}