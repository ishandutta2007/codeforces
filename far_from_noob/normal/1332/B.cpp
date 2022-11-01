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
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}

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
        cin>>n;
        ll a[n];
        fo(i,n)cin>>a[i];
        //vector<ll >v;
        //vector<ll>v[11];
        ll b[11]={2,3,5,7,11,13,17,19,23,29,31};
        //cout<<b[10];
        ll temp=0;
        ll color[n];
        map<ll,ll>m1;
        ll count=0;
        fo(i,n){
            color[i]=0;
            fo(j,11){if(a[i]%b[j]==0){color[i]=j+1;if(m1[j+1]==0){m1[j+1]=1; count++;} break;}}
        }
        map<ll,ll>m2;
        temp=1;
        fo(i,11){
            if(m1[i+1]==1){
                m2[i+1]=temp;
                temp++;
            }
        }
        cout<<count<<endl;
        fo(i,n)cout<<m2[color[i]]<<" ";cout<<endl;
        //cout<<gcd(559 ,871);
        
    }

    return 0;
}