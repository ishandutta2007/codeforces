#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int n;
string s;
ll solve(){
	cin>>n>>s;
	int x[2]={0};
	for(char c:s) x[c-'0']+=1;
	ll ans=1LL*x[0]*x[1];
	for(int i=0,j;i<n;i=j) {
		for(j=i;j<n&&s[j]==s[i];++j);
		int len=j-i;
		ans=max(ans, 1LL*len*len);
	}
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
}