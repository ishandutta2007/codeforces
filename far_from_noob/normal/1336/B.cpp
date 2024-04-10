#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
vector<ll>v[200005];
ll child[200005];
vector<pair<ll,ll> >p;
void dfs(ll node, ll root ,ll height, ll n){
    ll temp=1;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        dfs(v[node][i], node , height+1, n);
        temp+=child[v[node][i]];
    }
    child[node]=temp;
    p.pb(mp(height-temp , temp));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>t;
    //t=1;
    while(t--){
        //cin>>n;
        ll cr,cg,cb;
        cin>>cr>>cg>>cb;
        ll r[cr];
        set<ll>g;
        set<ll>b;
        g.insert(-1000000000);
        b.insert(-1000000000);
        g.insert(2000000000);
        b.insert(2000000000);
        fo(i,cr)cin>>r[i];
        fo(i,cg){
            cin>>k;
            g.insert(k);
        }  
        fo(i,cb){
            cin>>k;
            b.insert(k);
        }
        set<ll> :: iterator it1,it;
        ll ans=8*1e18;
        //cout<<ans<<" ";
        ll temp,pp,qq;
        fo(i,cr){
            it=g.lower_bound(r[i]);
             pp=*it;
             temp=(r[i]+pp)/2;
            it1=b.lower_bound(temp);
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));
            //cout<<r[i]<< pp << qq <<" ";

            it1--;
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));

            it--;
             pp=*it;
             temp=(r[i]+pp)/2;
            it1=b.lower_bound(temp);
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));
            it1--;
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));


            it=b.lower_bound(r[i]);
             pp=*it;
             temp=(r[i]+pp)/2;
            it1=g.lower_bound(temp);
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));

            it1--;
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));

            it--;
             pp=*it;
             temp=(r[i]+pp)/2;
            it1=g.lower_bound(temp);
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));
            it1--;
             qq=*it1;
            ans=min(ans, (r[i]-pp)*(r[i]-pp) + (r[i]-qq)*(r[i]-qq) + (qq-pp)*(qq-pp));

        }
        cout<<ans<<endl;
     }

    return 0;
}