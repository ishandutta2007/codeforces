#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=4e5+1;
const int iu=20;
ll n,m;
ll d[N*2],d2[N*2];
bool v[N*2],v2[N*2];
ll ans=1e18;
vector<int>adj[N],rev[N];
typedef pair<ll,int> pli;
ll d3[N*2];
vector<int>bin[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		u--;v--;
		adj[u].push_back(v);
		adj[v+n].push_back(u+n);
	}
	{
		for(int i=0; i<2*n ;i++){
			d[i]=1e18;v[i]=0;
		}
		d[0]=0;
		priority_queue<pli,vector<pli>,greater<pli> >pq;
		pq.push({0,0});
		while(!pq.empty()){
			int x=pq.top().se;pq.pop();
			if(v[x]) continue;
			v[x]=true;
			for(auto c:adj[x]){
				if(d[c]>d[x]){
					d[c]=d[x];
					pq.push({d[c],c});
				}
			}
			if(d[(x+n)%(2*n)]>d[x]+1){
				int nx=(x+n)%(2*n);
				d[nx]=d[x]+1;
				pq.push({d[nx],nx});
			}
		}
	}
	if(min(d[n-1],d[2*n-1])>=iu){
		for(int i=0; i<2*n ;i++){
			d2[i]=1e18;v[i]=0;
		}
		d2[0]=0;
		priority_queue<pli,vector<pli>,greater<pli> >pq;
		pq.push({0,0});
		while(!pq.empty()){
			int x=pq.top().se;pq.pop();
			if(v[x]) continue;
			v[x]=true;
			for(auto c:adj[x]){
				if(d[c]==d[x] && d2[c]>d2[x]+1){
					d2[c]=d2[x]+1;
					pq.push({d2[c],c});
				}
			}
			if(d[(x+n)%(2*n)]==d[x]+1){
				int nx=(x+n)%(2*n);
				if(d2[nx]>d2[x]){
					d2[nx]=d2[x];
					pq.push({d2[nx],nx});
				}
			}
		}
		ll ans=0;
		ll mn=min(d[n-1],d[2*n-1]);
		for(int i=1; i<=mn ;i++) ans=(ans*2+1)%mod;
		ll f=1e18;
		if(d[n-1]==mn) f=min(f,d2[n-1]);
		if(d[2*n-1]==mn) f=min(f,d2[2*n-1]);
		ans=(ans+f)%mod;
		cout << ans << '\n';
		return 0;
	}
	{
		for(int i=0; i<2*n ;i++) d3[i]=1e18;
		d3[n]=0;
		ll f=0;
		ll ans=1e18;
		for(int j=0; j<iu ;j++){
			int c=j%2;
			int p=c^1;
			for(int i=0; i<n ;i++){
				d3[c*n+i]=d3[p*n+i];v[i]=v[i+n]=0;
				if(d3[p*n+i]<n) bin[d3[p*n+i]].push_back(c*n+i);
			}
			for(int i=0; i<n ;i++){
				while(!bin[i].empty()){
					int x=bin[i].back();bin[i].pop_back();
					if(v[x]) continue;
					v[x]=true;
					for(auto c:adj[x]){
						
						//cout << j << ' ' << x << ' ' << c << endl;
						if(d3[c]>d3[x]+1){
							d3[c]=d3[x]+1;
							if(d3[c]<n) bin[d3[c]].push_back(c);
						}
					}
				}
			}
			ans=min(ans,f+d3[c*n+n-1]);
			f=2*f+1;
		}
		cout << ans%mod << '\n';
	}
}