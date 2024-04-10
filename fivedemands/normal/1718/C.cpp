#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e5+1;
const int iu=2e5;
ll n,m;
vector<int>pf[N];
multiset<ll>s[6];
ll a[N];
ll sco[N][6];
void upd(int j,int id,ll v){
	s[j].erase(s[j].find(sco[id][j]));
	sco[id][j]+=v;
	s[j].insert(sco[id][j]);
}
void solve(){
	cin >> n >> m;
	int z=pf[n].size();
	for(int i=0; i<n ;i++){
		for(int j=0; j<z ;j++){
			sco[i][j]=0;
		}
	}
	for(int j=0; j<z ;j++){
		s[j].clear();
		for(int i=0; i<n/pf[n][j] ;i++){
			s[j].insert(0);
		}
	}
	for(int i=0; i<n ;i++){
		cin >> a[i];
		for(int j=0; j<z ;j++){
			upd(j,i%(n/pf[n][j]),a[i]);
		}
	}
	{
		ll ans=0;
		for(int j=0; j<z ;j++){
			ll god=*s[j].rbegin();
			ans=max(ans,god*(n/pf[n][j]));
		}
		cout << ans << '\n';
	}
	for(int k=0; k<m ;k++){
		int i;ll x;cin >> i >> x;
		i--;
		for(int j=0; j<z ;j++){
			upd(j,i%(n/pf[n][j]),x-a[i]);
		}
		a[i]=x;
		{
			ll ans=0;
			for(int j=0; j<z ;j++){
				ll god=*s[j].rbegin();
				ans=max(ans,god*(n/pf[n][j]));
			}
			cout << ans << '\n';
		}
	}
	//cout << "lololo " << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i=2; i<=iu ;i++){
		if(!pf[i].empty()) continue;
		for(int j=i; j<=iu ;j+=i){
			pf[j].push_back(i);
		}
	}
	int t;cin >> t;while(t--) solve();
}