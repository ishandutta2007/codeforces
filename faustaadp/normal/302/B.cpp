#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
ll n,m,i,ta,tb,l[101010],r[101010],hz,j;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        l[i]=hz+1;
        r[i]=hz+ta*tb;
        hz+=ta*tb;
    }
    i=1;
    for(j=1;j<=m;j++)
    {
        cin>>ta;
        while(!(l[i]<=ta&&ta<=r[i]))
            i++;
        cout<<i<<"\n";
    }
}