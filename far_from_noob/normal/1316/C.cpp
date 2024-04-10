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
    	ll p;
    	cin>>n>>m>>p;
    	ll a[n];
    	ll b[m];
    	fo(i,n)cin>>a[i];
    	fo(i,m)cin>>b[i];
    	ll count=0;
    	flag=-1;
    	fo(i,min(m,n)){
    		if(a[i]%p==0 && b[i]%p ==0)count++;
    		else if(a[i]%p==0 && b[i]%p !=0){
    			flag=0;
    			break;
    		}
    		else if(a[i]%p!=0 && b[i]%p ==0){
    			flag=1;
    			break;
    		}
    		else {
    			cout<<2*count;
    			return 0;
    		}

    	}
    	if(flag==0){
    		//ll temp=0;
    		for(int i=count+1;i<n;i++){
    			if(a[i]%p!=0){
    				cout<<2*count+i-count;
    				return 0;
    			}
    		}
    	}
    	if(flag==1){
    		//ll temp=0;
    		//cout<<count;
    		for(int i=count+1;i<m;i++){
    			if(b[i]%p!=0){
    				cout<<2*count +i-count;
    				return 0;
    			}
    		}
    	}


    }

    return 0;
}