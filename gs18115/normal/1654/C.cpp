#include<iostream>
#include<vector>
#include<queue>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        ll s=0;
        for(int&t:v)
            cin>>t,s+=t;
        ll sm=s,smc=1,lrc=0;
        sort(all(v),greater<int>());
        int ci=0;
        bool fl=0;
        while(ci<n&&sm>0)
        {
            while(ci<n&&sm+1==v[ci])
                ci++,lrc--;
            while(sm>=3&&ci<n&&sm==v[ci])
                ci++,smc--;
            if(lrc<0||smc<0)
            {
                fl=1;
                break;
            }
            ll nsmc=0,nlrc=0;
            if(sm==2)
                nsmc=lrc,nlrc=smc+lrc;
            else if(sm==1)
                nlrc=smc+lrc*2;
            else if(sm%2==1)
                nsmc=smc,nlrc=smc+2*lrc;
            else
                nsmc=smc*2+lrc,nlrc=lrc;
            smc=nsmc,lrc=nlrc;
            sm/=2;
        }
        while(ci<n&&sm+1==v[ci])
            ci++,lrc--;
        if(lrc<0||smc<0)
            fl=1;
        if(fl)
            cout<<"NO\n";
        else if(ci==n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}