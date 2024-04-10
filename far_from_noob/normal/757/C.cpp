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
    ll fac[1000005];
    //ll infac[500005];
    fac[0]=1;
    fo(i,1000003){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    
    // for(int i=2;i<100002;i++){
    //     infac[i]=infac[i-1]*po(i,mod-2,1,1,i)%mod;
    // }
    while(t--){
        cin>>n>>m;
        ll g[n];
        ll ans[m+1];
        fo1(i,m)ans[i]=1;
        ll count=2;
        fo(j,n){
            cin>>g[j];
            vector<ll>v;
            fo(i,g[j]){cin>>q; v.pb(q);}
            sort(all(v));
            vector<pair<ll,ll> >p ;
            fo(i,g[j]){
                if(i==0)p.pb(mp(1,v[i]));
                else{
                    if(v[i]==v[i-1])p[p.size()-1].fi++;
                    else p.pb(mp(1,v[i]));
                }
            }
            sort(all(p));
            //fo(i,p.size())cout<<p[i].fi<<"-"<<p[i].se<<"  ";cout<<endl;

            vector<pair<ll,ll> >p1;
            fo(i,p.size()){
                ll temp= p[i].se;
                if(i==0)p1.pb(mp(ans[temp],temp));
                else{
                    if(p[i].fi==p[i-1].fi)p1.pb(mp(ans[temp],temp));
                    else{
                        sort(all(p1));
                        fo(l,p1.size()){
                            if(l==0)ans[p1[l].se]=count;
                            else{
                                if(p1[l].fi==p1[l-1].fi);
                                else count++;
                                ans[p1[l].se]=count;
                            }
                        }
                        if(p1.size()>0)count++;
                        p1.clear();
                        p1.pb(mp(ans[temp],temp));
                    }
                }
            }
            sort(all(p1));
            fo(i,p1.size()){
                            if(i==0)ans[p1[i].se]=count;
                            else{
                                if(p1[i].fi==p1[i-1].fi);
                                else count++;
                                ans[p1[i].se]=count;
                            }
            }
            if(p1.size()>0)count++;


        }
        //l;
        sort(ans+1,ans+m+1);
        //fo1(i,m)cout<<ans[i]<< " ";cout<<endl;
        
        ll finalans=1;
        count=0;
        fo1(i,m){
            if(i==1)count++;
            else{
                if(ans[i]==ans[i-1])count++;
                else{
                    //cout<<count<< " ";
                    finalans*=fac[count];
                    finalans%=mod;
                    count=1;
                }
            }
        } 
        //cout<<count<<endl;
        finalans*=fac[count];
        finalans%=mod;

        // fo(i,1000005){
        //     finalans*=fac[m1[i]];
        //     finalans%=mod;
        // }
        cout<<finalans;

        
    }

    return 0;
}