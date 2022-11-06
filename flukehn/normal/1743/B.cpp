#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	For(i,0,n) a[i]=i+1;
	if (n>=2)swap(a[1], a[n-1]);
	For(i,0,n)cout<<a[i]<<" \n"[i+1==n];
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}