//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<ii> al1[100005];
vector<ii> al2[100005];

int w[100005];
priority_queue<ii,vector<ii>,greater<ii> > pq;


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		al1[a].pub({b,c});
		al2[b].pub({a,c});
	}
	
	memset(w,1,sizeof(w));
	
	w[1]=0;
	pq.push({w[1],1});
	while (!pq.empty()){
		int weight,u; tie(weight,u)=pq.top(); pq.pop();
		if (w[u]!=weight) continue;
		
		for (auto [it,ww]:al1[u]){
			if (w[it]>w[u]+ww){
				w[it]=w[u]+ww;
				pq.push({w[it],it});
			}
		}
	}
	
	rep(x,1,n+1) pq.push({w[x],x});
	while (!pq.empty()){
		int weight,u; tie(weight,u)=pq.top(); pq.pop();
		if (w[u]!=weight) continue;
		
		for (auto [it,ww]:al2[u]){
			if (w[it]>w[u]+ww){
				w[it]=w[u]+ww;
				pq.push({w[it],it});
			}
		}
	}
	
	rep(x,2,n+1) cout<<(w[x]==w[0]?-1:w[x])<<" "; cout<<endl;
}