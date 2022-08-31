#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,q;
ll suma;
ll a[100001];
ll b[100001];
vector<ll>v;
ll sumb=-2e18;
ll ans(){
	if(v.size()==1){
		return abs(v[0]-suma);
	}
	if(v[m-n]<=suma){
		return suma-v[m-n];
	}
	else if(v[0]>=suma){
		return v[0]-suma;
	}
	int l=0,r=v.size()-2,mid;
	while(l!=r){
		mid=(l+r+1)/2;
		if(v[mid]<=suma) l=mid;
		else r=mid-1;
	}
	//cout << suma << ' ' << v[0] << ' ' << v[1] << endl;
	return min(v[l+1]-suma,suma-v[l]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(i%2==1) suma+=a[i];
		else suma-=a[i];
	}
	for(int i=0; i<=m-n ;i++) v.push_back(0);
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(i%2==1) v[0]+=b[i];
		else v[0]-=b[i];
	}
	sumb=v[0];
	for(int i=1; i<=m-n ;i++){
		cin >> b[n+i];
		v[i]=-v[i-1]+b[i];
		if((n)%2==1) v[i]+=b[i+n];
		else v[i]-=b[i+n];
	}
	sort(v.begin(),v.end());
	cout << ans() << endl;
	for(int i=1; i<=q ;i++){
		int l,r;
		ll v;
		cin >> l >> r >> v;
		if(r%2==1 && l%2==1) suma+=v;
		else if(r%2==0 && l%2==0) suma-=v;
		cout << ans() << endl;
	}
}