#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
int n;
int m=1e5;
int a[100001];
vector<int>v[100001];
int f[201];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	ll s=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		ll y;cin >> y;
		s+=y;
		v[a[i]].push_back(y);
	}
	ll ans=0;
	for(int i=1; i<=m ;i++){
		int c=v[i].size();
		c-=1;
		ll t=0,s=0;
		for(auto d:v[i]) s+=d;
		for(int i=200; i>=1 ;i--){
			int x=min(c,f[i]);
			c-=x;
			s+=x*i;
		}
		ans=max(ans,s);
		for(auto d:v[i]) f[d]++;
	}
	cout << s-ans << endl;
}