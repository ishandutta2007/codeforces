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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int&t:a)
            cin>>t;
        int k;
        cin>>k;
        vector<int>b(k);
        for(int&t:b)
            cin>>t;
        vector<pl>av,bv;
        for(int&t:a)
        {
            ll x=t,y=1;
            while(x%m==0)
                x/=m,y*=m;
            if(!av.empty()&&av.back().fi==x)
                av.back().se+=y;
            else
                av.eb(x,y);
        }
        for(int&t:b)
        {
            ll x=t,y=1;
            while(x%m==0)
                x/=m,y*=m;
            if(!bv.empty()&&bv.back().fi==x)
                bv.back().se+=y;
            else
                bv.eb(x,y);
        }
        if(av==bv)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}