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
        //fo(i,s.size())printf("%c",s[i]);
        ll l=s.size();
        ll temp=0;
        for(int i=0;i<l/2;i++){
            if(s[i]==s[l-1-i])temp++;
            else break;
        }
        ll maxi=0,index1=temp-1;
        for(int i=temp;i< l-temp; i++){
            flag=0;
            for(int j=temp;j<=i;j++){
                if(s[j]== s[i+temp-j]);
                else flag=1;
            }
            if(flag==0){
                index1=i;
            }
        }
        //cout<<s;
        //cout<<temp<<index1;
        ll index2=l-temp;
        for(int i= l-1-temp; i >= temp;i--){
            flag=0;
            for(int j=l-1-temp;j>=i;j--){
                if(s[j]== s[i+l-1-temp-j]);
                else flag=1;
            }
            if(flag==0){
                index2=i;
            }
        }
        //cout<<temp<<index1<<index2;
        if(index1+1 >= l-index2 ){
            fo(i,index1+1)cout<<s[i];
            for(int i= l-temp;i<l;i++)cout<<s[i];
        }
        else{
            fo(i,temp)cout<<s[i];
            for(int i=index2;i<l;i++)cout<<s[i];
        }
        cout<<endl;
        
    }

    return 0;
}