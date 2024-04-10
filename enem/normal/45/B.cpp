#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

static const ll N=100005;
static ll n,m,ans,rat,nod,lst,ad[N][20],v[N],b[N],sub[N],adn[N];
static bool vis[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    REP(i,0,n)
    {
        cin>>ad[i][0];
        ad[i][0]--;
        vis[i]=false;
    }
    REP(j,1,20)
    {
        REP(i,0,n)
        {
            ad[i][j]=ad[ad[i][j-1]][j-1];
        }
    }
    REP(i,0,m)
    {
        cin>>v[i];
        v[i]--;
    }
    REP(i,0,m)
    {
        cin>>b[i];
    }
    ans=0;
    REP(i,0,m)
    {
        nod=(ans+v[i])%n;
        rat=b[i];
        lst=nod;
        REP(j,0,20)
        {
            if((1<<j)&(rat))
            {
                lst=ad[lst][j];
            }
        }
        ans=0;
        while(rat>0)
        {
            ll tmp1;
            ll tmp2;
            if(vis[nod])
            {
                tmp1=sub[nod];
                tmp2=adn[nod];

                if(sub[nod]<rat)
                {
                    sub[nod]=rat;
                    adn[nod]=lst;
                }
            }
            else
            {
                tmp1=1;
                tmp2=ad[nod][0];
                ans++;

                vis[nod]=true;
                sub[nod]=rat;
                adn[nod]=lst;
            }
            rat-=tmp1;
            nod=tmp2;
        }
        cout<<ans<<'\n';
    }

    return 0;
}