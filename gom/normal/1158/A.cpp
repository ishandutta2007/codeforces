#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,int> PP;
const int N=5e5+5;
const ll MOD=1e9+7;
int n,m;
ll ans,mx,a[N],b[N],cnt;
priority_queue<P> pq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        a[i]=x;
        mx=max(mx,x);
        ans+=x*(ll)m;
        pq.push(P(x,m-1));
    }
    for(int i=1;i<=m;i++){
        ll x;
        cin>>x;
        if(x<mx){
            cout<<-1;
            return 0;
        }
        b[i]=x;
        if(x==mx) cnt++;
        ans+=x-mx;
    }
    sort(a+1,a+1+n);
    if(!cnt) ans+=a[n]-a[n-1];
    cout<<ans;
    return 0;
}