#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef long long ll;
const int N=1e6+1;
int n,m;
int fx[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		fx[x]++;
	}
	int ans=n;
	for(int i=1; i<=m ;i++){
		ans=min(ans,2*n-fx[i]*2);
	}
	cout << ans << endl;
	for(int i=1; i<=n/2-1 ;i++){
		int mx=0;
		for(int j=1; j<=m ;j++){
			if(fx[j]>fx[mx]) mx=j;
		}
		int mx2=0;
		for(int j=1; j<=m ;j++){
			if(fx[j]>fx[mx2] && j!=mx) mx2=j;
		}
		if(mx2==0) mx2=mx;
		fx[mx]--;fx[mx2]--;
		cout << mx << ' ' << mx2 << '\n';
		cout << mx2 << ' ' << mx << '\n';
	}
	vector<int>v;
	for(int i=1; i<=m ;i++){
		for(int j=0; j<fx[i] ;j++) v.push_back(i);
	}
	if(v.size()==1){
		cout << v[0] << ' ' << v[0] << '\n';
	}
	if(v.size()==2){
		cout << v[0] << ' ' << v[1] << '\n';
		cout << v[1] << ' ' << v[0] << '\n';
	}
	if(v.size()==3){
		cout << v[0] << ' ' << v[1] << '\n';
		cout << v[1] << ' ' << v[2] << '\n';
		cout << v[2] << ' ' << v[0] << '\n';
	}
}