#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int pos=1;
	ll ans=0;
	for(int i=1; i<=m ;i++){
		cin >> a[i];
		int dis=a[i]-pos+n;
		dis%=n;
		pos=a[i];
		ans+=dis;
	}
	cout << ans << endl;
}