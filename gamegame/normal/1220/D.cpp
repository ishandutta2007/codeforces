#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
pair<ll,ll>a[200001];
int ans=0,id;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		a[i]={x&-x,x};
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		int l=i,r=i;
		while(r<n && a[r+1].fi==a[l].fi) r++;
		if(ans<r-l+1){
			ans=r-l+1;id=l;
		}
		i=r;
	}
	cout << n-ans << '\n';
	for(int i=1; i<=n ;i++) if(i<id || i>=id+ans) cout << a[i].se << ' ';
}