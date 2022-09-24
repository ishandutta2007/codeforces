#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mx=66000;
int ps1[20][mx],ps2[20][mx];
int ind;
inline int get1(int x)
{
    return x<0?0:ps1[ind][x];
}
inline int get2(int x)
{
    return x<0?0:ps2[ind][x];
}
int lsbt[mx],msbt[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,q;
    cin>>k>>q;
    const int unit=1<<k;
    vector<pair<pl,int> >qv(q);
    for(auto&t:qv)
    {
        ll&l=t.fi.fi;
        ll&r=t.fi.se;
        int&v=t.se;
        cin>>l>>r>>v;
        for(int i=0;i<16;i++)
        {
            if((v>>i&1)==0)
                continue;
            if(l/unit==r/unit)
            {
                ps1[i][l%unit]++;
                ps1[i][(r%unit)+1]--;
            }
            else if(l/unit+1==r/unit)
            {
                ps1[i][0]++;
                ps1[i][r%unit+1]--;
                ps1[i][l%unit]++;
                ps1[i][unit]--;
            }
            else
            {
                ps1[i][0]++;
                ps1[i][unit]--;
            }
            ps2[i][l/unit]++;
            ps2[i][r/unit+1]--;
        }
    }
    for(int i=0;i<16;i++)
    {
        ind=i;
        for(int j=0;j<unit;j++)
            ps1[i][j+1]+=ps1[i][j],ps2[i][j+1]+=ps2[i][j];
        for(int j=0;j<unit;j++)
            ps1[i][j]=ps1[i][j]>0?1:0,ps2[i][j]=ps2[i][j]>0?1:0;
        for(int j=0;j<unit;j++)
            lsbt[j]|=ps1[i][j]<<i,msbt[j]|=ps2[i][j]<<i;
        for(int j=0;j<unit;j++)
            ps1[i][j+1]+=ps1[i][j],ps2[i][j+1]+=ps2[i][j];
        for(auto&t:qv)
        {
            ll&l=t.fi.fi;
            ll&r=t.fi.se;
            int&v=t.se;
            if((v>>i&1)==1)
                continue;
            if(l/unit==r/unit)
            {
                if(get2(l/unit)-get2(l/unit-1)>0&&get1(r%unit)-get1(l%unit-1)>0)
                    return cout<<"impossible"<<endl,0;
            }
            else if(l/unit+1==r/unit)
            {
                if(get2(l/unit)-get2(l/unit-1)>0&&get1(unit-1)-get1(l%unit-1)>0)
                    return cout<<"impossible"<<endl,0;
                if(get2(r/unit)-get2(r/unit-1)>0&&get1(r%unit)>0)
                    return cout<<"impossible"<<endl,0;
            }
            else
            {
                if(get2(l/unit)-get2(l/unit-1)>0&&get1(unit-1)-get1(l%unit-1)>0)
                    return cout<<"impossible"<<endl,0;
                if(get2(r/unit)-get2(r/unit-1)>0&&get1(r%unit)>0)
                    return cout<<"impossible"<<endl,0;
                if(get2(r/unit-1)-get2(l/unit)>0&&get1(unit-1)>0)
                    return cout<<"impossible"<<endl,0;
            }
        }
    }
    cout<<"possible"<<endl;
    for(int i=0;i<unit;i++)
        cout<<lsbt[i]<<'\n';
    for(int i=0;i<unit;i++)
        cout<<msbt[i]<<'\n';
    return 0;
}