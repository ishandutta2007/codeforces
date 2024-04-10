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
const ll INF=1e18+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll&t:a)
        cin>>t;
    ll s=-INF*4;
    ll e=INF*4;
    while(s<e)
    {
        ll m=s+(e-s)/2;
        ll sm=0;
        for(ll&t:a)
        {
            ll cs=0;
            ll ce=t;
            while(cs<ce)
            {
                ll cm=cs+(ce-cs)/2;
                if(t-3*cm*cm-3*cm>m)
                    cs=cm+1;
                else
                    ce=cm;
            }
            sm+=cs;
        }
        if(sm>k)
            s=m+1;
        else
            e=m;
    }
    vector<ll>b;
    ll sum=0;
    for(ll&t:a)
    {
        ll cs=0;
        ll ce=t;
        while(cs<ce)
        {
            ll cm=cs+(ce-cs)/2;
            if(t-3*cm*cm-3*cm>s)
                cs=cm+1;
            else
                ce=cm;
        }
        b.eb(cs);
        sum+=cs;
    }
    priority_queue<pl>pq;
    for(int i=0;i<n;i++)
        if(b[i]<a[i])
            pq.ep(a[i]-3*b[i]*b[i]-3*b[i],i);
    for(;sum<k;sum++)
    {
        int i=pq.top().se;
        pq.pop();
        b[i]++;
        if(b[i]<a[i])
            pq.ep(a[i]-3*b[i]*b[i]-3*b[i],i);
    }
    for(ll&t:b)
        cout<<t<<' ';
    cout<<endl;
    return 0;
}