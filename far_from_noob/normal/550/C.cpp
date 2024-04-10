#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
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
        string s;
        cin>>s;
        ll l=s.size();
        fo(i,l){
            if(s[i]=='8'  || s[i]=='0'){
                cout<<"YES"<<endl<<s[i]-'0';
                return 0;
            }
        }
        fo(i,l){
            if(s[i]!='0'){
                for(int j=i+1;j<l;j++){
                    if(((s[i]-'0')* 10 + (s[j]-'0') ) %8 ==0){
                        cout<<"YES"<<endl<<((s[i]-'0')* 10 + (s[j]-'0') );
                        return 0;
                    }
                }
            }
        }
        fo(i,l){
            if(s[i]!='0'){
                for(int j=i+1;j<l;j++){
                    for(int h=j+1;h<l;h++){
                        if(((s[i]-'0')* 100 + (s[j]-'0')*10 + (s[h]-'0') ) %8 ==0){
                        cout<<"YES"<<endl<<((s[i]-'0')* 100 + (s[j]-'0')*10 + (s[h]-'0') );
                        return 0;
                        }
                    }
                }
            }
        }
        cout<<"NO";
    }

    return 0;
}