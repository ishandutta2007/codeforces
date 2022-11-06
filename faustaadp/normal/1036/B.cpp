#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,has,q,m,x,y;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>q;
    while(q--)
    {
        cin>>n>>m>>k;
        if(k<max(n,m))
            has=-1;
        else
        {
            has=min(n,m);
            x=k-min(n,m);
            y=max(n,m)-min(n,m);
            if((x%2)==1&&(y%2)==0)
                has=has+x-2;
            else
            if((x%2)==0&&(y%2)==0)
                has+=x;
            else
            if((x%2)==0&&(y%2)==1)
                has=has+x-1;
            else
                has=has+x-1;
        }
        cout<<has<<"\n";
    }
}