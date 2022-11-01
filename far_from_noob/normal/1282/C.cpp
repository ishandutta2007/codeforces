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
    	ll time,a,b;
    	cin>>n>>time>>a>>b;
    	ll type[n],det[n];
    	ll c0=0,c1=0;
    	fo(i,n)cin>>type[i];
		fo(i,n)cin>>det[i];
		vector<pair<ll,ll> >v;
		fo(i,n){
			if(type[i]==0)c0++;
			else c1++;
			v.pb(mp(det[i],type[i]));
		}    	
		sort(all(v));
		ll count0=0,count1=0;
		ll ans=0;
		fo(i,n){
			ll ans1=0;
			if(i==0){
				if(v[i].fi-1-a*count0- b*count1>=0)
				{
				ll kk=v[i].fi-1-a*count0- b*count1;
				ans1=count0+count1;
				if(kk>(c0-count0)*a){
					ans1= c0 + min(c1,(v[i].fi-1-c0*a)/b);
				}
				else ans1+= kk/a;
				}
			}
			else if(v[i].fi!=v[i-1].fi){
				if(v[i].fi-1-a*count0- b*count1>=0)
				{
				ll kk=v[i].fi-1-a*count0- b*count1;
				ans1=count0+count1;
				if(kk>(c0-count0)*a){
					ans1= c0 + min(c1,(v[i].fi-1-c0*a)/b); 
				}
				else ans1+= kk/a;
				}
				//cout<<v[i].fi<<ans1<<endl;
			}
			ans=max(ans1,ans);

			if(v[i].se==0)count0++;
			else count1++;

		}
		ll ans1=0;
		if(time-a*count0- b*count1>=0)
		{
			ll kk=time-a*count0- b*count1;
			ans1=count0+count1;
			if(kk>(c0-count0)*a){
				ans1= c0 + min(c1,(time-c0*a)/b); 
			}
			else ans1+= kk/a;
		}
		ans=max(ans,ans1);
		cout<<ans<<endl;

    }

    return 0;
}