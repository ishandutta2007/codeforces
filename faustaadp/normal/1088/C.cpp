#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],tam,tambahan;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<n+1<<"\n";
    for(i=(n-1);i>=0;i--)
    {
        a[i]+=tam;
        tambahan=i-(a[i]%n);
        if(tambahan<0)tambahan+=n;
        cout<<1<<" "<<(i+1)<<" "<<tambahan<<"\n";
        tam+=tambahan;
    }
    cout<<2<<" "<<n<<" "<<n<<"\n";
}