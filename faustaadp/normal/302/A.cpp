#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
ll n,q,i,ta,tb,a[10];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        ta++;
        a[ta]++;
    }
    while(q--)
    {
        cin>>ta>>tb;
        if((tb-ta+1)%2==0&&(a[2]>=(tb-ta+1)/2)&&a[0]>=(tb-ta+1)/2)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
}