#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,bisa,tem;
char a[202020];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        bisa=1;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n/2;i++)
        {
            tem=n-i+1;
            if(abs(a[i]-a[tem])!=0&&abs(a[i]-a[tem])!=2)
                bisa=0;
        }
        if(bisa)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}