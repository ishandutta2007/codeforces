#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n,m,k;
ll a[N];
ll l[N],r[N],d[N];
ll dx[N];
ll ex[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> l[i] >> r[i] >> d[i];
	}
	for(int i=1; i<=k ;i++){
		ll x,y;cin >> x >> y;
		dx[x-1]++;
		dx[y]--;
	}
	ll cur=dx[0];
	for(int i=1; i<=m ;i++){
		d[i]*=cur;
		cur+=dx[i];
		ex[l[i]-1]+=d[i];
		ex[r[i]]-=d[i];
	}
	cur=ex[0];
	for(int i=1; i<=n ;i++){
		a[i]+=cur;
		cur+=ex[i];
		cout << a[i] << ' ';
	}
}