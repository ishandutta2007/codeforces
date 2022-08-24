#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const ll N=2e6+1;
ll n,m;
ll a[N],b[N];
int c[N],d[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> b[i];
		int dir=0;
		if(a[i]>b[i]){
			swap(a[i],b[i]);dir=1;
		}
		if(a[i]>n || b[i]<=n) return cout << "-1\n",0;
		c[a[i]]=b[i];d[a[i]]=dir;
	}
	set<int>s;
	for(int i=0; i<=n ;i++) s.insert(n+i);
	vector<int>use;use.push_back(0);
	for(int i=1; i<=n ;i++){
		s.erase(c[i]);
		if(i+*s.rbegin()==2*n) use.push_back(i);
	}
	int ans=0;
	for(int i=1; i<use.size() ;i++){
		int l=use[i-1]+1,r=use[i];
		int mn=1e9;
		int mx=1e9;
		int res=0;
		for(int j=l; j<=r ;j++){
			if(c[j]>mn){
				if(c[j]>mx) return cout << "-1\n",0;
				res+=(d[j]!=1);
				mx=c[j];
			}
			else{
				res+=(d[j]!=0);
				mn=c[j];
			}
		}
		ans+=min(res,r-l+1-res);
	}
	cout << ans << '\n';
}