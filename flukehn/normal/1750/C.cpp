#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int n;
string s,t;
int f[N], tot;
using pa=pair<int,int>;
vector<pa> ans;
void wk(int l,int r){
	f[l] ^= 1;
	f[r + 1] ^= 1;
	tot += 1;
	ans.emplace_back(l, r);
}
int solve(){
	cin>>n>>s>>t;
	for(int i=0;i<=n+1;++i) f[i]=0;
	tot=0;
	ans.clear();
	char c= (s[0]-'0') ^ (t[0] - '0');
	For(i,1,n) if( ((s[i]-'0')^(t[i]-'0')) != c) return 0;
	cout<<"YES\n";
	for(int i=0,j;i<n;i=j){
		for(j=i;j<n&&s[j]==s[i];++j);
		if(s[i]=='1') {
			wk(i+1,j);
		}
	}
	for(int i=1;i<=n;++i) f[i] ^= f[i-1];
	for(int i=1;i<=n;++i) f[i] ^= (tot % 2) ^ (t[i-1] - '0');
	//for (int i=1;i<=n;++i) debug(f[i] << " \n"[i==n]);
	for(int i=2;i<=n;++i) assert(f[i] == f[i-1]);
	if (f[1] == 1) {
		wk(1, 1);
		wk(2, 2);
		wk(1, 2);
	}
	cout << ans.size() << "\n";
	for (auto [l,r]:ans) cout << l << " " << r << "\n";
	return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		if(!solve()){
			cout<<"NO\n";
		}
	}	
}