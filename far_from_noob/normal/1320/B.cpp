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
    	cin>>n>>m;
    	vector<ll>v1[n+1];
    	vector<ll>v2[n+1];
    	fo(i,m){
    		ll a,b;
    		cin>>a>>b;
    		v1[a].pb(b);
    		v2[b].pb(a);
    	}
    	ll k;
    	cin>>k;
    	ll path[k];
    	fo(i,k)cin>>path[i];
    	ll node=path[k-1];
       	ll mindis[n+1];
       	fo1(i,n)mindis[i]=mod;
       	mindis[node]=0;
       	ll temp=0;
       	queue<ll>q;
       	q.push(node);
       	while(q.size()>0){
       		//cout<<q.size()<<endl;
       		ll l=q.size();
       		temp++;
       		fo(i,l){
       			ll curr=q.front();
       			q.pop();
       			fo(j,v2[curr].size()){
       				if(mindis[v2[curr][j]]<=temp);
       				else {mindis[v2[curr][j]] =temp ; q.push( v2[curr][j] );}
       			}
       		}
       		//cout<<q.size()<<endl;
       	}
       	ll mini=k;
       	//fo1(i,n)cout<<mindis[i]<<" ";
       	ll pa[k+1];
       	fo(i,k)pa[i]=0;
       	for(int i=k-1;i>=0;i--){
       		if(mindis[path[i]] == k-1-i )mini--,pa[i]=1;
       		else {
       			//cout<<path[i];
       			if(mindis[path[i+1]]== mindis[path[i]]-1)
       			{mini--; pa[i]=1;}
       		}
       	}
       	ll maxi=k-1;
       	for(int i=k-2;i>=0;i--){
       		if(pa[i]==0){continue;}
       		ll curr=path[i];
       		ll count=0;
       		fo(j,v1[curr].size()){
       			if(mindis[v1[curr][j]] == mindis[curr]-1)count++;
       		}
       		//cout<<curr<<count<<endl;
       		if(count==1)maxi--;
       	}
       	cout<<mini<<" "<<maxi;

    	
    }

    return 0;
}