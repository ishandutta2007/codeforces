#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,has,d[55];
char a[101010],b[101010];
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
        if(a[i]=='0'&&b[i]=='0')
        {
            has+=d[2]+d[3];
            d[0]++;
        }
        else
        if(a[i]=='0'&&b[i]=='1')
        {
            has+=d[2];
            d[1]++;
        }
        else
        if(a[i]=='1'&&b[i]=='0')
        {
            has+=d[0]+d[1];
            d[2]++;
        }
        else
        {
            has+=d[0];
            d[3]++;
        }
    }
    cout<<has<<"\n";
}