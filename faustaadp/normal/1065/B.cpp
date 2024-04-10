#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,MI,i,MA,L,R,C;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    MI=max(0LL,n-m*2);
    L=0;
    R=n;
    while(L<=R)
    {
        C=(L+R)/2;
        if((((n-C)*(n-C-1))/2)>=m)
        {
            MA=C;
            L=C+1;
        }
        else
            R=C-1;
    }
    cout<<MI<<" "<<MA<<"\n";
}