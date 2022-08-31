#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m,a,b;
map<int,int>mp;
multiset<pair<int,int> >s;
vector<vector<int> >ans;
vector<pair<int,int> >v;
int f[400001];
void solve(int x){
	cout << x << endl;
	cout << f[x] << ' ' << x/f[x] << endl;
	ans.resize(f[x]);
	for(int i=0; i<f[x] ;i++){
		ans[i].resize(x/f[x]);
	}
	for(auto cur:s){
		for(int i=0; i<cur.fi ;i++) v.push_back({cur.fi,cur.se});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int cx=0,cy=0;
	for(int i=0; i<v.size() ;i++){
		//cout << cx << ' ' << (cx+cy)%(x/f[x]) << endl;
		ans[cx][(cx+cy)%(x/f[x])]=v[i].se;
		cx++;
		if(cx==f[x]) cx=0,cy++;
	}
	for(int i=0; i<f[x] ;i++){
		for(auto cur:ans[i]) cout << cur << ' ';
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		mp[x]++;
	}
	for(auto cur:mp) s.insert({cur.se,cur.fi});
	for(int i=1; i<=n ;i++){
		for(long long j=1LL*i*i; j<=n ;j+=i) f[j]=i;
	}
	for(int i=n; i>=1 ;i--){
		auto it=s.end();
		--it;
		//cout << it->fi << ' ' << it->se << endl;
		if(it->fi<=f[i]){
			solve(i);
			return 0;
		}
		int cur=it->se;
		s.erase(it);
		mp[cur]--;
		if(mp[cur]!=0) s.insert({mp[cur],cur});
	}
	while(true);
}