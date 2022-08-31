#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m,s;
pair<pair<ll,ll>,int> a[N];
ll t[N];
ll b[N];
typedef pair<ll,ll> pll;
bool sm(pll x,pll y){
	if(x.fi/x.se!=y.fi/y.se) return x.fi/x.se<y.fi/y.se;
	x.fi%=x.se;y.fi%=y.se;
	return x.fi*y.se<x.se*y.fi;
}
bool cmp(pair<pll,int>x,pair<pll,int>y){
	if(sm(x.fi,y.fi)) return true;
	if(sm(y.fi,x.fi)) return false;
	return x.se<y.se;
}
int c[N];
int d[N];
int gp[N];
void solve(){
	cin >> n >> m;s=0;
	for(int i=1; i<=n ;i++){
		cin >> t[i];
	}
	sort(t+1,t+n+1);
	reverse(t+1,t+n+1);
	n=min(n,m);
	for(int i=1; i<=m ;i++){
		int k;cin >> k;
		for(int j=1; j<=k ;j++) gp[s+j]=i;
		
		ll tot=0;
		for(int j=1; j<=k ;j++){
			cin >> b[j];
			tot+=b[j];
		}
		a[i]={{tot,k},i};
		for(int j=1; j<=k ;j++){
			a[m+s+j]={{tot-b[j],k-1},m+s+j};
		}
		s+=k;
	}
	for(int i=1; i<=n ;i++){
		a[m+s+i]={{t[i],1},m+s+i};
	}
	sort(a+1,a+m+s+n+1,cmp);
	vector<int>bad,weak;
	for(int i=1; i<=m+s+n ;i++){
		c[a[i].se]=i;
		d[i]=0;
	}
	for(int i=1; i<=n ;i++){
		d[c[m+s+i]]--;
	}
	for(int i=1; i<=m ;i++){
		d[c[i]]++;
	}
	int mn=0;
	for(int i=1; i<=m+s+n ;i++){
		d[i]+=d[i-1];
		mn=min(mn,d[i]);
		if(d[i]==0) weak.push_back(i);
		if(d[i]==-1) bad.push_back(i);
	}
	if(mn<-1){
		for(int i=1; i<=s ;i++) cout << '0';
		cout << '\n';
		return;
	}
	for(int i=1; i<=s ;i++){
		int rmv=c[gp[i]];
		int put=c[i+m];
		bool res;
		if(put<rmv){
			if(bad.empty()) res=true;
			else if(rmv>bad.back() && put<=bad[0]) res=true;
			else res=false;
		}
		else{
			if(!bad.empty()) res=false;
			else{
				auto it=lower_bound(weak.begin(),weak.end(),rmv);
				if(it!=weak.end() && *it<put) res=false;
				else res=true;
			}
		}
		cout << res;
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}