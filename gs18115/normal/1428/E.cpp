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
inline ll get(ll v,int cut)
{
    ll s1=v/cut;
    ll s2=s1+1;
    ll c2=v-s1*cut;
    ll c1=cut-c2;
    return c1*s1*s1+c2*s2*s2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll&t:v)
        cin>>t;
    ll ans=0;
    priority_queue<pl>pq;
    vector<int>cut(n);
    for(int i=0;i<n;i++)
    {
        ans+=v[i]*v[i];
        cut[i]=1;
        if(v[i]!=1)
            pq.ep(get(v[i],1)-get(v[i],2),i);
    }
    for(int it=n;it<k;it++)
    {
        pl ct=pq.top();
        pq.pop();
        int i=ct.se;
        ans-=ct.fi;
        cut[i]++;
        if(cut[i]<v[i])
            pq.ep(get(v[i],cut[i])-get(v[i],cut[i]+1),i);
    }
    cout<<ans<<endl;
    return 0;
}