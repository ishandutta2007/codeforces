#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int solve(){
	int n;
	cin>>n;
	vector<int> s(n),t(n);
	For(i,0,n) cin>>s[i];
	For(i,0,n) cin>>t[i];
	int ans=0;
	For(i,0,n) ans+=s[i]!=t[i];
	int ans2=1;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	For(i,0,n) ans2+=s[i]!=t[i];
	return min(ans,ans2);
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
}