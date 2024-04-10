#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=1e9+7;
const ll INF=1e18;
const int N=2e5+5;
int w,l;
vector<int> ans;
map<int,bool> mp;
void Do(int x){
    for(int i=1;i*i<=x;i++) if(x%i==0){
        if(mp.find(i)==mp.end()){
            ans.emplace_back(i); mp[i]=1;
        }
        if(mp.find(x/i)==mp.end()){
            ans.emplace_back(x/i); mp[x/i]=1;
        }
    }
}
void solve(){
    cin>>w>>l;
    ans.clear(); mp.clear();
    ans.emplace_back(1); mp[1]=1;
    ans.emplace_back(2); mp[2]=1;
    Do(__gcd(w-1,l-1)); Do(__gcd(w-2,l)); Do(__gcd(w,l-2));
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<" ";
    for(auto x: ans) cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}