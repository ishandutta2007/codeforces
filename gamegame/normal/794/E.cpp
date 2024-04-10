#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
ll n,m;
ll a[N];
ll b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	ll mx=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	ll odd=0,even=0;
	for(int i=0; i<n ;i++){
		if((n-i)%2==0){
			ll f=max(a[(n-i)/2],a[(n-i)/2+1]);
			ll g=max(a[(n+i)/2],a[(n+i)/2+1]);
			even=max(even,max(f,g));
			cout << even << ' ';
		}
		else if(i==n-1){
			cout << mx << ' ';
		}
		else{
			int ps=(n-i+1)/2;
			ll f=min(a[ps],max(a[ps-1],a[ps+1]));
			ps=(n+i+1)/2;
			ll g=min(a[ps],max(a[ps-1],a[ps+1]));
			odd=max(odd,max(f,g));
			cout << odd << ' ';
		}
	}
}