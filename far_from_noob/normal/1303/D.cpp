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
#define fo(i,n) for(ll i=0;i<n;i++)
#define fo1(i,n) for(ll i=1;i<=n;i++)
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
   // t=1;
    while(t--){
    	cin>>m >>n;
    	ll a[n];
    	ll b[60];
    	fo(i,60)b[i]=0;
    	multiset<ll>s;
    	multiset <ll> :: iterator it;
    	s.insert(-1);
    	s.insert(1e18 + 7);
    	fo(i,n){
    		cin>>a[i],s.insert(a[i]);
    		b[(ll)log2(a[i])]++;
    	}
    	
    	ll count=0;
    	flag=0;
    	ll c[60];
    	if(m>1e15){cout<<-1<<endl; continue;}
    	for(ll i=59;i>=0;i--){
    		if(m>= (ll)pow(2,i)){c[i]=1;
    		m-=  (ll)pow(2,i);}
    		else c[i]=0;
    	}
    	for(ll i=0;i<60;i++){
    		if(c[i]==1){
    			//cout<<i<<" ";
    			ll kk=1;
    			if(b[i]>=1)b[i]--,kk--;
    			else if(i>0){
    				if(b[i-1]==2)b[i-1]-=2,kk--;
    			}
    			if(kk==1){
    				for(ll j=i+1;j<60;j++){
    					if(b[j]>=1){count++; b[j]--;break;}
    					else b[j]=1,count++;
    					if(j==59)flag=1;
    				}
    			}
    		}
    		
    			if(i<59)b[i+1]+=b[i]/2;
    		
    	}


    	if(flag==1)cout<<-1<<endl;
    	else cout<<count<<endl;

    	
    }

    return 0;
}