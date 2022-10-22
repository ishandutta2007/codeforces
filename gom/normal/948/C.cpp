#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
ll n,v[N],t[N],ans[N],csum,tree[N];
set<P>st;
void add(int x,ll v)
{
    for(;x<=n;x+=x&-x)
        tree[x]+=v;
}
ll get(int x)
{
    ll v=0;
    for(;x;x-=x&-x)
        v+=tree[x];
    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=n+1;i++){
        set<P>::iterator it1,it2;
        if(i!=n+1)st.insert(P(v[i]+csum,i));
        it1=st.upper_bound(P(csum+t[i],i));
        it2=st.lower_bound(P(csum,i));
        if(i==n+1)
            it1=st.end();
        for(;it2!=it1;it2++){
            ll tt=(*it2).first,arr=(*it2).second;
            ans[i]+=tt-csum;
            add(arr,1);
            add(i,-1);
        }
        csum+=t[i];
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]+get(i)*t[i]<<" ";
    return 0;
}