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
ll n,k,t1,m,q,flag=0;
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t1=1;
    while(t1--){
        cin>>n;
        map<ll,ll>val;
        map<ll,ll>maxi;
        multiset<ll>s;
        ll a[n];
        ll t[n];
        fo(i,n){
            cin>>a[i];
            
        }
        multiset<pair<ll,ll> >p;
        fo(i,n){
          cin>>t[i];
          p.insert(mp(a[i],t[i]));
        }
        multiset<pair<ll,ll> >:: iterator it,it1;
        multiset<ll> :: iterator it2;
        it = p.begin();
        //set<ll>temp;
        //sort(p,p+n);
        ll sum=0;
        ll ans=0;
        while(it!=p.end()){
            pair<ll,ll>temp=*it;
            it1=it;
            it1++;
            pair<ll,ll>temp1=*it1;
            s.insert(temp.se);
            sum+=temp.se;
            
            if(it1!=p.end())if(temp.fi==temp1.fi){
                it++;
                continue;
            }
            it2=s.end();
            it2--;
            ll kk =*it2;
            ans+=sum-kk;
            if(sum!=kk ){
                p.insert( mp(temp.fi+1 , 0) );
            }
            sum-=kk;
            s.erase(it2);
            //cout<<temp.fi<<" "<<ans<<" ";
            it++;

        }
        cout<<ans;
        
    }

    return 0;
}