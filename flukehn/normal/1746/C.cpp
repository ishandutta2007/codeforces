#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
int n,a[N];
using pii=pair<int,int>;
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<pii> b;
	for(int i=1;i<n;++i) if(a[i]>a[i+1]) b.emplace_back(a[i]-a[i+1], i+1);
	sort(b.begin(), b.end());
	int lf=1;
	vector<int> p;
	for(auto [w, i]: b){
		while(lf<w) p.push_back(1),++lf;
		p.push_back(i);
		++lf;
	}
	while(lf<=n) p.push_back(1),++lf;
	For(i,0,n)cout<<p[i]<<" \n"[i+1==n];
}
int main(){
#ifdef flukehn
	freopen("C.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}