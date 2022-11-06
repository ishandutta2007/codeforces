#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll x,i,j;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=x;j++)
        {
            if((i*j>x)&&(i<x*j)&&(i%j==0))
            {
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }
    cout<<-1<<"\n";
}