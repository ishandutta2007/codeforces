#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s,d;
    cin>>n>>s>>d;
    int n1=(s*2+2)/3;
    int n2=s-n1;
    mt19937_64 gen(12892374);
    vector<ull>vv(n);
    for(ull&t:vv)
        t=gen();
    vector<ull>prs;
    for(int i=0;i<s;i++)
    {
        int c;
        cin>>c;
        ull cur=0;
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            cur^=vv[x-1];
        }
        prs.eb(cur);
    }
    vector<pair<ull,int> >pv1,pv2;
    pv1.reserve((1<<n1)+1);
    pv1.eb(0,0);
    for(int j=0;j<n1;j++)
        for(int sz=pv1.size(),i=0;i<sz;i++)
            pv1.eb(pv1[i].fi^prs[j],pv1[i].se+1);
    pv2.reserve((1<<n2)+1);
    pv2.eb(0,0);
    for(int j=n1;j<s;j++)
        for(int sz=pv2.size(),i=0;i<sz;i++)
            pv2.eb(pv2[i].fi^prs[j],pv2[i].se+1);
    sort(all(pv1));
    for(int i=0;i<d;i++)
    {
        int c;
        cin>>c;
        ull cur=0;
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            cur^=vv[x-1];
        }
        int ans=inf;
        for(auto&t:pv2)
        {
            auto it=lower_bound(all(pv1),pair<ull,int>(cur^t.fi,0));
            if(it!=pv1.end()&&it->fi==(cur^t.fi))
                ans=min(ans,it->se+t.se);
        }
        if(ans==inf)
            ans=-1;
        cout<<ans<<'\n';
    }
    return 0;
}