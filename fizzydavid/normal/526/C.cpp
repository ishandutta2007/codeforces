//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll c,hr,hb,wr,wb;
int main()
{
    cin>>c>>hr>>hb>>wr>>wb;
    if(wr<wb)
    {
        swap(hr,hb);
        swap(wr,wb);
    }
    if(wr<100000)
    {
        ll ans=0;
        for(int i=0;i<=wr;i++)
        {
            if(c-i*wb<0)continue;
            ans=max(ans,i*hb+(c-i*wb)/wr*hr);
        }
        for(int i=0;i<=wb;i++)
        {
            if(c-i*wr<0)continue;
            ans=max(ans,i*hr+(c-i*wr)/wb*hb);
        }
        cout<<ans<<endl;
    }
    else
    {
        ll ans=0;
        for(int i=0;i<=c/wr;i++)
        {
            ans=max(ans,i*hr+(c-i*wr)/wb*hb);
        }
        cout<<ans<<endl;
    }
    return 0;
}