#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll gets(int x,int y){
	ll ans=0,res=0;
	cout << "and " << x << ' ' << y << endl;
	cin >> res;ans+=res;
	cout << "or " << x << ' ' << y << endl;
	cin >> res;ans+=res;
	return ans;
}
ll a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	ll x=gets(1,2);
	ll y=gets(1,3);
	ll z=gets(2,3);
	ll s=(x+y+z)/2;
	a[1]=s-z;
	a[2]=s-y;
	a[3]=s-x;
	for(int i=4; i<=n ;i++){
		ll w=gets(1,i);
		a[i]=w-a[1];
	}
	sort(a+1,a+n+1);
	cout << "finish " << a[m] << endl;
}