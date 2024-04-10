#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,d[1010],sat;
char ta;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<"Yes\n";
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        d[ta]++;
    }
    for(i='a';i<='z';i++)
    {
        if(d[i]==1)
        {
            sat++;
        }
    }
    if(sat==n)
        cout<<"No\n";
    else
        cout<<"Yes\n";
}