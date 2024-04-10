#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
//#define endl "\n"
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
    	cin>>n;
    	vector<ll>v[n+1];
    	fo(i,n-1){
    		ll a,b;
    		cin>>a>>b;
    		v[a].pb(b);
    		v[b].pb(a);
    	}
    	vector<ll>temp;
    	map<ll,ll>m1;
    	map<ll,ll>m2;
    	
    	ll node,curr;
    	curr=1;
    	while(1){
    		vector<ll>v1;
    		fo(i,v[curr].size()){
    			if(m1[v[curr][i]]==0)v1.pb(v[curr][i]);
    		}
    		ll kk=curr;
    		for(int i=0;i<v1.size();i+=2){
    			m1[curr]=1;
    			if(i<v1.size()-1){
    				cout<<"? "<<v1[i]<<" "<<v1[i+1]<<endl;
    				cin>>node;
    				if(node!=curr){
    					curr=node;
    					break;
    				}
    			}
    			else {
    				m1[curr]=0;
    				m2[curr]=-1;
    				//curr=v1[i];
    				if(m2[v1[i]]==-1)
    				{cout<<"? "<<v1[i]<<" "<<curr<<endl;
    				cin>>node;
    				cout<<"! "<<node;
    				return 0;
    				}
    				else curr=v1[i];
    			}
    		}
    		if(curr==kk){
    					cout<<"! "<<curr;
    					return 0;
    		}
    	}
    	// fo1(i,n){
    	// 	if(v[i].size()==1){
    	// 		temp.pb(i);
    	// 		m1[i]++;
    	// 	}
    	// }
    	// ll node;
    	// ll i=0;
    	// while(temp.size()>1+i){
    	// 	
    	// 	m1[temp[i]]--;
    	// 	m1[temp[i+1]]--;
    	// 	//cout.flush();
    	// 	cin>>node;
    	// 	if(m1[node]==0){temp.pb(node);m1[node]++;}
    	// 	i+=2;

    	// }
    	// cout<<"! "<<temp[i];



    	
    }

    return 0;
}