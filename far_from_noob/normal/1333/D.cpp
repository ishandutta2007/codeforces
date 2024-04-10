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
        cin>>n>>k;
        char c[n];
        fo(i,n)cin>>c[i];
        vector<ll>v[n];
        ll temp=n;
        ll maxcount=0;
        fo(i,n){
            fo(j,n-1){
                if(c[j]=='R' && c[j+1]=='L'){
                    v[i].pb(j+1);
                    c[j]='L';
                    c[j+1]='R';
                    j++;
                    maxcount++;
                }
            }
            if(v[i].size()==0){
                temp=i;
                break;
            }
        }
        ll kk=0;
        //cout<<temp<<k<<maxcount;
        if(maxcount <k || k<temp){
            cout<<-1;
            return 0;
        }
        
        else{
            fo(i,temp){
                ll l=0;
                while(k>temp-i && l<v[i].size()){
                    k--;
                    cout<<1<<" "<<v[i][l]<<endl;
                    l++;
                }


                if(l<v[i].size()){
                    cout<<v[i].size()-l<<" ";
                    k-=1;
                    for(;l<v[i].size();l++)cout<<v[i][l]<<" ";
                    cout<<endl;
                }

            }
        }
        
    }

    return 0;
}