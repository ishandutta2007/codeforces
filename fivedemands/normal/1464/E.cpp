#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long T;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int out[N];
int nim[N];
vector<int>adj[N],rev[N];
///tourist github
void hadamard(vector<ll> &a) {
  ll n = 1;
  while (n < (ll) a.size()) {
    n <<= 1;
  }
  a.resize(n);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        T x = a[i + j];
        T y = a[i + j + k];
        a[i + j] = (x + y)%mod;
        a[i + j + k] = (x - y+mod)%mod;
      }
    }
  }
}
//end tourist github
vector<ll>v;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return pw(x,y-1)*x%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		rev[v].push_back(u);
		adj[u].push_back(v);
		out[u]++;
	}
	stack<int>s;
	for(int i=1; i<=n ;i++){
		if(out[i]==0) s.push(i);
	}
	while(!s.empty()){
		int x=s.top();s.pop();
		for(auto &c:adj[x]){
			c=nim[c];
		}
		sort(adj[x].begin(),adj[x].end());
		adj[x].erase(unique(adj[x].begin(),adj[x].end()),adj[x].end());
		for(auto c:adj[x]){
			if(c!=nim[x]) break;
			nim[x]++;
		}
		for(auto c:rev[x]){
			if(--out[c]==0){
				s.push(c);
			}
		}
	}
	v.resize(n);
	ll fk=pw(n+1,mod-2);
	for(int i=1; i<=n ;i++){
		v[nim[i]]=((v[nim[i]]-fk)%mod+mod)%mod;
	}
	v[0]=(v[0]+1)%mod;
	//fwht<ll>g;
	hadamard(v);
	for(int i=0; i<v.size() ;i++){
		v[i]%=mod;v[i]+=mod;v[i]%=mod;
		if(v[i]==0) while(true);
		v[i]=pw(v[i],mod-2);
	}
	hadamard(v);
	v[0]%=mod;v[0]+=mod;v[0]%=mod;
	ll ans=v[0]*pw(1LL*v.size()*(n+1)%mod,mod-2)%mod;
	ll res=(mod+1-ans)%mod;
	cout << (res+mod)%mod << endl;
}