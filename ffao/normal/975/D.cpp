    #include <bits/stdc++.h>
    #define int long long
    using namespace std;
    typedef long long ll;
    const int N=2e5+10;
    ll a[N];
    typedef pair<int,int> pp;
    map<pp,ll> mp1;
    unordered_map<ll,ll> mp2;
    void solve()
    {
        int n,a,b; scanf("%lld%lld%lld",&n,&a,&b);
        for(int i=1;i<=n;i++){
            int x,vx,vy; scanf("%lld%lld%lld",&x,&vx,&vy);
            mp2[a*vx-vy]++;
            mp1[{vx,vy}]++;
        }
        int res=0;
        for(auto it:mp2) res+=(it.second-1)*it.second;
        for(auto it:mp1) res-=(it.second-1)*it.second;
        printf("%lld\n",res);
    }
    signed main(){
        solve();
    #ifndef ONLINE_JUDGE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
        return 0;
    }