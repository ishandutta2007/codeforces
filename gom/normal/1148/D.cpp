#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> TP;
const int N=7e5+5;
const ll MOD=1e9+7;
int n,m,k,ans,to[N];
P arr[N],a[N],b[N];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].fi>>arr[i].se;
        to[arr[i].fi]=i;
        if(arr[i].fi>arr[i].se) a[++m]=arr[i];
        else b[++k]=arr[i];
    }
    if(m>k){
        sort(a+1,a+1+m);
        cout<<m<<"\n";
        for(int i=1;i<=m;i++) cout<<to[a[i].fi]<<" ";
    }
    else{
        sort(b+1,b+1+k);
        reverse(b+1,b+1+k);
        cout<<k<<"\n";
        for(int i=1;i<=k;i++) cout<<to[b[i].fi]<<" ";
    }
    return 0;
}