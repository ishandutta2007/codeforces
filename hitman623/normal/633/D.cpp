#include <bits/stdc++.h>
#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        10000000007LL
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
unordered_map<int,int> mp;
int a[1003];
void solve()
{
    int n,ans=0;
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        mp[a[i]]++;
        if(a[i]==0) ans++;
    }
    rep(i,0,n){
        rep(j,0,n){
            if(i==j) continue;
            int f1=a[i],f2=a[j],cnt=2;
            if(f1==0 && f2==0) continue;
            vi v;
            mp[a[i]]--;
            mp[a[j]]--;
            while(1){
                int cur=f1+f2;
                f1=f2;
                f2=cur;
                if(abs(f2)>hell) break;
                if(mp.find(f2)!=mp.end() && mp[f2]>0) v.pb(f2),mp[f2]--,cnt++;
                else break;
            }
            mp[a[i]]++;
            mp[a[j]]++;
            for(auto x:v){
                mp[x]++;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}