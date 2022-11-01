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
    cin>>t;
    //t=1;
    while(t--){
        string s;
        cin>>s;
        vector<ll>v;
        fo(i,s.size()){
            if(i<=1);
            else {
                if(s[i]=='o'&& s[i-1]=='w'&& s[i-2]=='t'){
                    if(i<s.size()-2){if(s[i+1]=='n'&& s[i+2]=='e'){v.pb(i);i+=2;continue;} else v.pb(i-1);}
                    else v.pb(i-1);
                }
                if(s[i]=='e'&& s[i-1]=='n'&& s[i-2]=='o')v.pb(i-1);

            }
        }
        cout<<v.size()<<endl;
        fo(i,v.size())cout<<v[i]+1<<" ";cout<<endl;
        

        
    }

    return 0;
}