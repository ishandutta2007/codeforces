#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,has;
char c[1010101];
pair<ll,ll> A[1010101];
pair<ll,ll> B[1010101];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=1;i<=n;i++)
    {
        A[i]=A[i-1];
        if(c[i]=='(')
            A[i].se=A[i-1].se+1;
        else
        {
            if(A[i-1].se==0)A[i].fi=A[i-1].fi+1;
            else A[i].se=A[i-1].se-1;
        }
    }
    for(i=n;i>=1;i--)
    {
        B[i]=B[i+1];
        if(c[i]==')')
            B[i].fi=B[i+1].fi+1;
        else
        {
            if(B[i+1].fi==0)B[i].se=B[i+1].se+1;
            else B[i].fi=B[i+1].fi-1;
        }
    }
    for(i=1;i<=n;i++)
    {
        pair<ll,ll> ki=A[i-1];
        //cout<<ki.fi<<" "<<ki.se<<"\n";
        if(c[i]==')')ki.se++;
        else
        {
            if(ki.se==0)ki.fi++;
            else ki.se--;
        }
        pair<ll,ll> ka=B[i+1];
        //cout<<ki.fi<<" "<<ki.se<<" "<<ka.fi<<" "<<ka.se<<"\n";
        if(ki.fi==0&&ka.se==0&&(ki.se==ka.fi))has++;
    }
    cout<<has<<"\n";
}