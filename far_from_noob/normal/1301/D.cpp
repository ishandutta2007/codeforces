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
    	cin>>n>>m>>k;
    	//cout<<4*n*m -2*n- 2*m;
    	if(k>4*n*m -2*n- 2*m){cout<<"NO"; return 0;}
    	cout<<"YES"<<endl;
    	vector<ll>v;
    	vector<string>s;
    	fo(i,m-1){
    		if(n>1){v.pb(n-1);
    		s.pb("D");}
    		if(n>1){v.pb(n-1);
    		s.pb("RLU");}
    		v.pb(1);
    		s.pb("R");

    	}
    	if(n>1){v.pb(n-1);
    	s.pb("D");
    	v.pb(n-1);
    	s.pb("U");}
    	if(m>1){v.pb(m-1);
    	s.pb("L");}
    	vector<pair<ll,string > >ans;
    	ll temp=0;
    	while(k>0){
    		if(k >= v[temp]* s[temp].size()){
    			k-=v[temp]* s[temp].size();
    			ans.pb( mp(v[temp], s[temp] ) );
    			temp++;
    		}
    		else{
    			ll l=s[temp].size();
    			if(k/l>0)ans.pb(mp(k/l, s[temp]) );
    			string str;
    			fo(i,k%s[temp].size())str.pb(s[temp][i]);
    			if(k%s[temp].size()!=0)ans.pb(mp(1,str ));
    			break;
    		}
    	}
    	cout<<ans.size()<<endl;
    	fo(i,ans.size()){
    		cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    	}
    	
    }

    return 0;
}