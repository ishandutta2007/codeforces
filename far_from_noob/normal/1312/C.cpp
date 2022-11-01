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
    	cin>>n>>k;
    	ll a[n];
    	fo(i,n)cin>>a[i];
    	sort(a,a+n);
    	map<ll,ll>m1;
    	flag=0;
    	fo(j,n){
    		ll temp=a[j];
    		ll kk = 1;
    		ll i=0;
    		while(temp>0){
    			//if(a[j]==1000)cout<<temp<<" ";
    			if(temp>=kk);
    			else {
    				flag=1;break;
    			}
    			if(temp%(kk*k)!=0){temp-=kk;
    				if(m1[i]==0)m1[i]=1;
    				else {flag=1; break;}
    			}
    			//if(a[j]==1000)cout<<temp<<" ";

    			
    			kk*=k;
    			i++;
    		}
    		if(flag==1)break;
    	}
    	if(flag==1)cout<<"NO"<<endl;
    	else cout<<"YES"<<endl;
    	
    }

    return 0;
}