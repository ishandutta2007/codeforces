#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0;
ll a[100001];
map<ll,ll>mp;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if(sum%2!=0) return cout << "NO\n",0;
	sum/=2;
	ll duh=sum;
	for(int i=1; i<=n ;i++){
		mp[a[i]]=true;
		sum-=a[i];
		if(mp[-sum] || sum==0) return cout << "YES\n",0;
	}
	mp.clear();
	sum=duh;
	reverse(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		mp[a[i]]=true;
		sum-=a[i];
		if(mp[-sum] || sum==0) return cout << "YES\n",0;
	}
	cout << "NO\n";
}