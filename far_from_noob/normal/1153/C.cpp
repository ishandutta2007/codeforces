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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a=0,b=0,c=0;
        char x[n];
        fo(i,n){cin>>x[i];
        if(x[i]== '(' )a++;
        if(x[i]== ')' )b++;
        if(x[i]== '?' )c++;
        }
        if(n%2==1){cout<<":(";return 0;}
        int temp=b;
        for(int i=n-1;i>=0;i--){
            if(x[i]=='?' && temp < n/2 )x[i]=')',temp++;
            else if(x[i]=='?') x[i]='(';
        }
        int c1=0,c2=0;
        fo(i,n){
            if(x[i]=='(')c1++;
            else c2++;
            if(c2>=c1 && i!=n-1){flag=1;break;}
        }
        if(flag||c1!=c2){cout<<":(";return 0;}
        else fo(i,n)cout<<x[i];
        
    }
 
    return 0;
}