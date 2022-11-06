#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,du,i;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    du=1;
    for(i=1;i<=100;i++)
    {
        du*=2;
        if((du-1)>=n)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
}