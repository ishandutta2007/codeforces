#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tem,t1,t2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        t1=tem/m;
        tem+=ta;
        t2=tem/m;
        cout<<t2-t1<<" ";
    }
}