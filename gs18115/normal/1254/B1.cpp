#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int M=1000010;
ll s;
int n,i;
int a[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s==0)
        return cout<<0<<endl,0;
    if(s==1)
        return cout<<-1<<endl,0;
    vector<ll>v;
    for(i=2;(ll)i*i<=s;i++)
    {
        if(s%i==0)
        {
            v.eb(i);
            while(s%i==0)
                s/=i;
        }
    }
    if(s>1)
        v.eb(s);
    ll ANS=INF;
    for(ll&p:v)
    {
        ll ans=0;
        ll m=0;
        for(i=0;i<n;i++)
        {
            ans+=min(m,p-m);
            m+=a[i];
            m%=p;
        }
        ANS=min(ANS,ans);
    }
    cout<<ANS<<endl;
    return 0;
}