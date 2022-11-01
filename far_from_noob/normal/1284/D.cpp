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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        pair<ll,ll>a[n],b[n];
        fo(i,n){
            ll c,d;
            cin>>c>>d;
            a[i]=mp(c,d);
            cin>>c>>d;
            b[i]=mp(c,d);
        }
        if(1){
        vector<pair<ll,ll> >v1,v2;
        multiset<ll>s1;
        multiset<ll>s2;
        s2.insert(mod);
        s1.insert(mod);
        s1.insert(0);
        s2.insert(0);
        fo(i,n){
            ll c,d;
            c=a[i].fi;
            d=a[i].se;
            v1.pb(mp(d,i));
            v2.pb(mp(c,i));
            c=b[i].fi;
            d=b[i].se;
            s1.insert(c);
            s2.insert(d);
        }
        sort(all(v1));
        sort(all(v2));
        ll temp=0;
        //flag=0;
        fo(i,n){
            if(flag)break;
            if(v2[temp].fi>v1[i].fi){
                ll l=v1[i].se;
                multiset<ll>::iterator it2=s2.lower_bound(b[l].fi );
                if(*it2 <= b[l].se)flag=1;
                multiset<ll>::iterator it1=s1.upper_bound(b[l].se );
                it1--;
                if(*it1 >= b[l].fi)flag=1;
            }
            else{
                ll l=v2[temp].se;
                multiset<ll>::iterator it1=s1.lower_bound(b[l].fi);
                s1.erase(it1);
                multiset<ll>::iterator it2=s2.lower_bound(b[l].se);
                s2.erase(it2);
                //cout<<i<<s1.size()<<s2.size()<<endl;
                temp++;
                i--;
            }
            
            if(temp==n)break;
            if(flag)break;
        }
        
        }
        if(1){
        vector<pair<ll,ll> >v1,v2;
        multiset<ll>s1;
        multiset<ll>s2;
        s2.insert(mod);
        s1.insert(mod);
        s1.insert(0);
        s2.insert(0);
        pair<ll,ll>c[n];
        fo(i,n){
            c[i]=b[i];
            b[i]=a[i];
            a[i]=c[i];
        }
        fo(i,n){
            ll c,d;
            c=a[i].fi;
            d=a[i].se;
            v1.pb(mp(d,i));
            v2.pb(mp(c,i));
            c=b[i].fi;
            d=b[i].se;
            s1.insert(c);
            s2.insert(d);
        }
        sort(all(v1));
        sort(all(v2));
        ll temp=0;
        //flag=0;
        fo(i,n){
            if(flag)break;
            if(v2[temp].fi>v1[i].fi){
                ll l=v1[i].se;
                multiset<ll>::iterator it2=s2.lower_bound(b[l].fi );
                if(*it2 <= b[l].se)flag=1;
                multiset<ll>::iterator it1=s1.upper_bound(b[l].se );
                it1--;
                if(*it1 >= b[l].fi)flag=1;
            }
            else{
                ll l=v2[temp].se;
                multiset<ll>::iterator it1=s1.lower_bound(b[l].fi);
                s1.erase(it1);
                multiset<ll>::iterator it2=s2.lower_bound(b[l].se);
                s2.erase(it2);
                //cout<<i<<s1.size()<<s2.size()<<endl;
                temp++;
                i--;
            }
            
            if(temp==n)break;
            if(flag)break;
        }
        }
 
        if(flag)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
 
        
    }
 
    return 0;
}