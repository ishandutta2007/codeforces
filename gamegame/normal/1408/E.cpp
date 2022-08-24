#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll m,n;
vector<int>v[N];
int boss;
ll a[N];
ll b[N];
int f[N];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	f[x]=y;
	return true;
}
vector<pair<ll,pair<int,int> > >e;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> m >> n;
	for(int i=1; i<=m ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
	}
	for(int i=1; i<=m ;i++){
		int k;cin >> k;
		for(int j=0; j<k ;j++){
			int x;cin >> x;
			e.push_back({a[i]+b[x],{n+i,x}});
		}
	}
	sort(e.begin(),e.end());reverse(e.begin(),e.end());
	for(int i=1; i<=m+n ;i++) f[i]=i;
	ll ans=0;
	for(auto c:e){
		if(!join(c.se.fi,c.se.se)) ans+=c.fi;
	}
	cout << ans << endl;
}