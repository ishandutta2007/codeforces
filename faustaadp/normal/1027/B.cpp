#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,has,ta,tb;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>q;
    while(q--)
    {
        has=0;
        cin>>ta>>tb;
        if(n%2==0)
        {
            if((ta+tb)%2==0)
            {
                if(ta%2==1)
                    has=n*(ta/2)+(tb+1)/2;
                else
                    has=n*(ta/2)+tb/2-(n/2);
            }
            else
            {
                if(ta%2==1)
                    has=(n*n/2)+(ta/2)*n+tb/2;
                else
                    has=(n*n/2)+(ta/2)*n+(tb+1)/2-(n/2);
            }
        }
        else
        {
            if((ta+tb)%2==0)
            {
                if(ta%2==1)
                    has=n*(ta/2)+(tb+1)/2;
                else
                    has=n*(ta/2)+tb/2-(n/2);
            }
            else
            {
                if(ta%2==1)
                    has=(n*n/2)+1+(ta/2)*n+tb/2;
                else
                    has=(n*n/2)+(ta/2)*n+(tb+1)/2-(n/2);
            }
        }
        cout<<has<<"\n";
    }
}