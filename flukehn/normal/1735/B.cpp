#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=111;
int n;
int a[N];
void solve(){
	cin>>n;
	For(i,0,n)cin>>a[i];
	sort(a,a+n);
	long long ans=0;
	For(i,1,n){
		if(a[i]>=2*a[0]){
			int x=a[i]-2*a[0]+1;
			ans+=(x+2*a[0]-2)/(2*a[0]-1);
		}
	}
	cout<<ans<<"\n";
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