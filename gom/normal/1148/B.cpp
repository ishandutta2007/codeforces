#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> TP;
const int N=7e5+5;
const ll MOD=1e9+7;
ll n,m,ta,tb,k,a[N],b[N],ans=-1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>ta>>tb>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    if(min(n,m)<=k){
        cout<<-1;
        return 0;
    }
    for(int i=0,j=-1;i<=k;i++){
        while(j+1<=m&&a[i+1]+ta>b[j+1]) j++;
        if(a[i+1]+ta>b[j]) j++;
        if(j>m){
            cout<<-1;
            return 0;
        }
        int d=k-i,e=j+d;
        if(e>m){
            cout<<-1;
            return 0;
        }
        //cout<<i<<" "<<j<<" "<<d<<" "<<e<<endl;
        ans=max(ans,b[e]+tb);
    }
    cout<<ans;
    return 0;
}