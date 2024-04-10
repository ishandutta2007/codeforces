#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
vector<int>sq[100001];
bool fun[100001];
vector<int>diu;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int k;cin >> k;
		for(int j=1; j<=k ;j++){
			int x;cin >> x;
			sq[i].push_back(x);
			if(j!=1 && sq[i][j-2]<sq[i][j-1]) fun[i]=true;
		}
	}
	ll duh=1;
	for(int i=1; i<=n ;i++){
		if(fun[i]) continue;
		diu.push_back(sq[i][0]);
	}
	sort(diu.begin(),diu.end());
	for(int i=1; i<=n ;i++){
		if(fun[i]) continue;
		ans+=lower_bound(diu.begin(),diu.end(),sq[i].back()+1)-diu.begin();
	}
	cout << 1LL*n*n-ans << '\n';
}