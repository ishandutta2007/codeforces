#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n;
string s;
//ll a[N],b[N];
ll dp[N];
bool solve(int t){
	int gd=n+1;
	int lc=0;
	for(int i=1; i<=n ;i++){
		if(s[i]=='.') continue;
		if(s[i]=='*'){
			if(lc>=i) continue;
			else gd=min(gd,i);
			continue;
		}
		int prv=i;
		gd=min(gd,i);
		if(t<i-gd) return false;
		int b=t-(i-gd)*2;
		lc=max(i,i+b);
		int c=t-(i-gd);
		c/=2;
		lc=max(lc,i+c);
		gd=n+1;
		//cout << t << ' ' << lc << endl;
	}
	if(gd==n+1) return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	//int t;cin >> t;while(t--) solve();
	cin >> n;
	cin >> s;
	n=s.size();
	s='?'+s;
	int l=0,r=3*n;
	while(l!=r){
		int mid=(l+r)/2;
		if(solve(mid)) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
}