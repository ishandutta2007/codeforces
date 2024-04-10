#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef vector<vector<ll>> mat;
const ll mod=998244353;
const int N=1e6+5;
int n;
ll a[N],x[N],s[N],c,sm,ans=1e18;
void Do(ll c)
{
    if(c==1) return;
    ll cur=0,res=0;
    while(cur!=sm){
        ll l=cur+1,r=cur+c,m=(l+r)/2;
        //for(int i=l;i<=r;i++) res+=abs(x[i]-x[m]);
        res+=s[r]-s[m]+(2*m-l-r)*x[m]-(s[m-1]-s[l-1]);
        cur=r;
    }
    ans=min(ans,res);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sm+=a[i];
        for(int j=1;j<=a[i];j++) x[++c]=i;
    }
    for(int i=1;i<=c;i++) s[i]=s[i-1]+x[i];
    if(sm==1){
        cout<<-1;
        return 0;
    }
    for(ll t=1;t*t<=sm;t++){
        if(sm%t==0) Do(t),Do(sm/t);
    }
    cout<<ans;
    return 0;
}