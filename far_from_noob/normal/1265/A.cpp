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
    	char s[3];
    	s[0]='a';
    	s[1]='b';
    	s[2]='c';
    	string str;
    	flag=0;
    	cin>>str;
    	fo(i,str.size()){
    		if(str[i]=='?'){
    			if(i==0)str[i]=s[0];
    			else str[i]='a'+ (str[i-1]-'a'+1)%3;
    			if(i<str.size()-1){
    				if(str[i]==str[i+1]){
    					str[i]='a'+(str[i]-'a'+1)%3;
    				}
    			}
    		}
    		else if(i<str.size()-1)if(str[i]==str[i+1])flag=1;

    	}
    	if(flag==1)cout<<-1<<endl;
    	else cout<<str<<endl;
    	
    }

    return 0;
}