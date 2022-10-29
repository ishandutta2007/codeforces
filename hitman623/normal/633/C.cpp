#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <bits/stdc++.h>
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
#define hell1        1000000007
#define hell2        1000000009
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
int n,m,dp[10004],p1=23,p2=31;
unordered_map<int,int> mp;
string t;
vector<string> ww(100005);
void solve()
{
    cin>>n>>t>>m;
    rep(i,1,m+1){
        cin>>ww[i];
        string temp=ww[i];
        int hash=0,cur1=1;
        for(auto &j:temp){
            j=tolower(j);
        }
        reverse(all(temp));
        for(auto j:temp){
            hash=(hash+1LL*j*cur1)%hell1;
            cur1=(1LL*cur1*p1)%hell1;
        }
        mp[hash]=i;
    }
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        string temp;
        int hash=0;
        int cur1=1,cur2=1;
        rep(j,i,n){
            hash=(hash+1LL*t[j]*cur1)%hell1;
            cur1=(1LL*cur1*p1)%hell1;
            if(dp[j+1] && mp.count(hash)){
                dp[i]=mp[hash];
                break;
            }
        }
    }
    int i=0;
    while(i<n){
        cout<<ww[dp[i]]<<" ";
        i+=ww[dp[i]].size();
    }
}

int main()
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