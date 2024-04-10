#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int iu=1.5e7;
int a[15000001];
bool p[15000001];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int n;
ll c[300001];
int main(){
	ios::sync_with_stdio(false);
	ll g=0;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
		g=gcd(g,c[i]);
	}
	for(int i=1; i<=n ;i++) a[c[i]/g]++;
	int ans=0;
	for(int i=2; i<=iu ;i++){
		if(p[i]) continue;
		int b=0;
		for(int j=i; j<=iu ;j+=i){
			b+=a[j];
			p[j]=true;
		}
		ans=max(ans,b);
	}
	if(ans==0) cout << "-1\n";
	else cout << n-ans << endl;
}