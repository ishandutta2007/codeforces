#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll x,U,i,C,D,tC,tD,A,B;
ll tanya(ll aa,ll bb)
{
    cout<<"? "<<aa<<" "<<bb<<endl;
    ll tempe;
    cin>>tempe;
   // if((A^aa)>(B^bb))return 1;
   // if((A^aa)==(B^bb))return 0;
   // if((A^aa)<(B^bb))return -1;
    return tempe;
}
ll buat1(ll aa)
{
    ll ii,H=0;
    for(ii=0;ii<aa;ii++)
        H+=(1<<ii);
    return H;
}
void sama(ll aa)
{
    ll ii;
    for(ii=aa;ii>=0;ii--)
    {
        tC=C;
        tD=D+(1<<ii);
        x=tanya(tC,tD);
        if(x==1)
        {
            C+=(1<<ii);
            D+=(1<<ii);
        }
    }
    cout<<"! "<<C<<" "<<D<<endl;
    exit(0);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cin>>A>>B;
    x=tanya(0,0);
    if(x==1)U=1;
    else if(x==-1)U=2;
    else sama(29);
    for(i=29;i>=0;i--)
    {
        tC=C+buat1(i);
        tD=D+buat1(i);
        x=tanya(tC,tD);
        if(U==1)
        {
            if(x==-1)
            {
                tC=C;
                tD=D+(1<<i);
                x=tanya(tC,tD);
                if(x==1)
                {
                    C+=(1<<i);
                    D+=(1<<i);
                }
            }
            else
            {
                C+=(1<<i);
                x=tanya(C,D);
                if(x==0)sama(i-1);
                else if(x==1)U=1;
                else U=2;
            }
        }
        else
        {
            if(x==1)
            {
                tC=C;
                tD=D+(1<<i);
                x=tanya(tC,tD);
                if(x==1)
                {
                    C+=(1<<i);
                    D+=(1<<i);
                }
            }
            else
            {
                D+=(1<<i);
                x=tanya(C,D);
                if(x==0)sama(i-1);
                else if(x==1)U=1;
                else U=2;
            }
        }
    }
}