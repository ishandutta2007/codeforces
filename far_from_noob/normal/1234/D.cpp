#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
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
    //cin>>t;
    t=1;
    while(t--){
        string s1;
        cin>>s1;
        ll k;
        set<ll>s[27];
        fo(i,26)s[i].insert(s1.size()+1);
        fo(i,s1.size()){
            s[s1[i]-'a'].insert(i+1);
        }
        cin>>k;
        //fo(i,26)cout<<s[i].size();
        fo(i,k){
            cin>>n;
            if(n==1){
                ll pos;
                char c;
                cin>>pos>>c;
                //cout<<c<<endl;
                
                s[s1[pos-1]-'a'].erase(pos);
                s[c-'a'].insert(pos);
                s1[pos-1]=c;
                //cout<<s1<<endl;
            }
            if(n==2){
                ll ans=0;
                ll l,r;
                cin>>l>>r;
                fo(i,26){
                    auto it =s[i].lower_bound(l);
                    //cout<<*it;
                    if(*it<=r)ans++;
                }
                cout<<ans<<endl;
            }
        }
        
        
        
    }

    return 0;
}