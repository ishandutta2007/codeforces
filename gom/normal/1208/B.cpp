#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const int N=2005;
const ll mod=1e9+7;
int n,a[N],bf[N],bf2[N],mn[N],mx[N],ans=1e9;
map<int,int> mp,mp2;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]) bf[i]=mp[a[i]];
		else{
			mp[a[i]]=i;
			bf[i]=1e9;
		}
		if(mp2[a[i]]) bf2[i]=mp2[a[i]];
		mp2[a[i]]=i;
	}
	mn[n+1]=1e9;
	for(int i=n;i>=1;i--) mn[i]=min(mn[i+1],bf[i]);
	for(int i=n;i>=1;i--) mx[i]=max(mx[i+1],bf2[i]);
	if(mn[1]==1e9){
		cout<<0;
		return 0;
	}
	///for(int i=1;i<=n;i++) cout<<bf[i]<<" "<<bf2[i]<<" "<<mn[i]<<" "<<mx[i]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<i<<" - "<<j<<" -> "<<mn[j+1]<<" "<<mx[j+1]<<endl;
			if(mn[j+1]<i) continue;
			if(mx[j+1]>=j+1) continue;
			//cout<<i<<" - "<<j<<endl;
			ans=min(ans,j-i+1);
			break;
		}
		if(bf[i]!=1e9) break;
	}
	cout<<ans;
    return 0;
}