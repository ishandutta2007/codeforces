#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef long long ll;
const int N=1e6+1;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << a[1] << endl;
		return 0;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll ans=a[1]-a[n];
	
	for(int j=2; j<n ;j++){
		if(a[j]<0) ans-=a[j];
		else if(j%2==0) ans+=a[j];
		else ans+=a[j];
	}
	cout << ans << endl;
}