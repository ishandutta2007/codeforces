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
        ll a ,b;
        cin>>a>>b;
        string s;
        ll x=0,y=0;
        cin>>s;
        n=s.size();
        pair<ll,ll>p[s.size()];
        ll maxx;
        fo(i,s.size()){
            if(s[i]=='U')y++;
            else if(s[i]=='R')x++;
            else if(s[i]=='D')y--;
            else if(s[i]=='L')x--;
            p[i]=(mp(x,y));
        }
        cout.precision(20);
        if(a==0&& b==0){cout<<"Yes"; return 0;}
        if(x==0 && y==0){
            fo(i,s.size()){
                if(a==p[i].fi && b==p[i].se)flag=1;
            }
        }
        
        else if(x==0){
            fo(i,s.size()){
            //cout<<p[i].fi<<p[i].se<<endl;
            if(abs((dd)((b-p[i].se)/y))== ((dd)b -(dd)p[i].se)/(dd)y){
                if(a==p[i].fi)flag=1;
            }
        }
        }
        else if(y==0){
                fo(i,s.size()){
            //cout<<p[i].fi<<p[i].se<<endl;
            if(abs((dd)((a-p[i].fi)/x))== ((dd)a -(dd)p[i].fi)/(dd)x){
                if(b==p[i].se)flag=1;
            }
        }
        }
        
        else fo(i,s.size()){
            //cout<<p[i].fi<<p[i].se<<endl;
            //if(i==4)cout<<((dd)a-(dd)p[i].fi)/(dd)x<<(a-p[i].se)/x<<" "<<(a-p[i].fi)/x<<endl;
            if(((dd)a-(dd)p[i].fi)/(dd)x == ((dd)b -(dd)p[i].se)/(dd)y){
                if(((dd)a-(dd)p[i].fi)/(dd)x == abs((dd)((a-p[i].fi)/x)) )flag=1;
            }
        }
        if(flag)cout<<"Yes";
        else cout<<"No";

        
    }

    return 0;
}