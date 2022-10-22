#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,ll> tup;
typedef vector<vector<ll>> mat;
const ll mod=998244353,inf=1e18;
const int N=2e5+5,M=55,K=1e5+5;
ll n,a[N],dp[N],ans;
map<ll,ll> mp;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=mp[a[i]-i]+a[i];
        mp[a[i]-i]=max(mp[a[i]-i],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}