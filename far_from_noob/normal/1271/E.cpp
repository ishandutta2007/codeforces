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
        ll l=0;
        for(int i=0;;i++){
            if((ll)pow(2,i)> n){
                l = i -1;break;
            }
        }
        ll power;
        ll temp=1;
        for(int i=l;i>=0;i--){
            if((ll)pow(2,temp) -2 + min(n+1-(ll)pow(2,l), (ll)pow(2,temp)  )  >=k){
                power=i; break;
            }
            temp++;
        }
        //cout<<l<<" "<<power<<" ";
        if(power==0){cout<<1;return 0;}
        if(power==l){
            if(k==1)cout<<n;
            else{
                if(n%2==0)cout<<n-2;
                else cout<<n-1;
            }
            return 0;
        }
        //cout<<temp<<endl;
        ll z=(n-(ll)pow(2,l)+1)/(ll)pow(2,temp);
        //cout<<z;
        if(k<= (ll)pow(2,temp) -2 ){
            if(k<=((ll)pow(2,temp) -2 )/2 ){cout<<(ll)pow(2,power+1)-1;}
            else cout<<(ll)pow(2,power+1)-2;
            return 0;
        }
        ll jj=(ll)pow(2,temp) -2 + (n-(ll)pow(2,l)+1)%(ll)pow(2,temp);
        //cout<<jj<<endl;
        if(k<=jj){
            //cout<<"Fdd";
            if(k<=jj/2)cout<<(ll)pow(2,power)+2*z+1;
            else cout<<(ll)pow(2,power)+2*z;
            return 0;
        }
        jj = (ll)pow(2,temp) -2 + (ll)pow(2,temp);
        if(k<=jj/2)cout<<(ll)pow(2,power)+2*z-1;
        else cout<<(ll)pow(2,power)+2*z-2;

        
    }

    return 0;
}