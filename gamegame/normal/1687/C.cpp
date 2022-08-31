#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
ll a[N],b[N];
vector<int>adj[N];
int on[N];
set<int>off;
stack<int>s;
int cnt[N];
void flush(int id){
	//cout << "flush " << id << endl;
	if(++cnt[id]>=2) while(true);
	for(auto c:adj[id]){
		if(on[c]){
			int l=min(c,id);
			int r=max(c,id);
			auto it=off.lower_bound(l);
			vector<int>ban;
			while(*it<=r){
				if(on[*it]) while(true);
				on[*it]=true;
				s.push(*it);
				int x=*it;
				ban.push_back(x);
				it++;
				//it=lower_bound(off.begin(),off.end(),l);
			}
			for(auto d:ban) off.erase(d);
			ban.clear();
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]+=a[i-1];
		
	}
	off.clear();
	while(!s.empty()) s.pop();
	for(int i=0; i<=n ;i++){
		adj[i].clear();
		on[i]=false;
		cnt[i]=0;
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		b[i]+=b[i-1];
	}
	for(int i=1; i<=m ;i++){
		int l,r;cin >> l >> r;
		l--;adj[l].push_back(r);adj[r].push_back(l);
	}
	for(int i=0; i<=n ;i++){
		if(a[i]==b[i]){
			on[i]=true;
			s.push(i);
		}
		else off.insert(i);
	}
	off.insert(n+1);
	while(!s.empty()){
		int x=s.top();s.pop();
		flush(x);
	}
	for(int i=0; i<=n ;i++){
		if(!on[i]){
			cout << "NO\n";return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}