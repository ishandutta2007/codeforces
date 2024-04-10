#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}
ll logg(ll a){
    if(pow(2,(ll)(log2(a))) == a)return log2(a);
    else return (ll)log2(a)+1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        ll l1=s1.size(), l2=s2.size();
        ll temp1=0,temp2=0;
        ll flag1=0;
        flag=0;
        for(int i=l2-1;i>=0;i--){
            if(s2[i]=='1'){temp2=l2-1-i;break;}
        }
        for(int i=l1-temp2-1;i>=0;i--){
            //if(s1[i]=='1'){flag1=1;continue;}
            if(s1[i]=='1'){
                temp1=l1-1-i;
                break;
            }
            
        }
        
        //cout<<temp1<<temp2<<endl;
        cout<<max(temp1-temp2,0)<<endl;
        
    }

    return 0;
}