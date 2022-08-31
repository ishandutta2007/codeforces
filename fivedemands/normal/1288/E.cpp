#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll p[300001];
ll a[300001];
ll last[300001];
ll bit[600001];
ll mn[300001],mx[300001];
void upd(int id,int v){
	for(int i=id; i<=n+m ;i+=i&-i) bit[i]+=v;
}
int qry(int id,int v){
	ll res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		p[i]=i;
		mn[i]=mx[i]=i;
		last[i]=n-i+1;
		upd(n-i+1,1);
	}
	for(int i=1; i<=m ;i++){
		int x;cin >> x;
		mn[x]=1;
		ll tmp=qry(last[x],1);
		mx[x]=max(mx[x],n-tmp+1);
		upd(last[x],-1);
		last[x]=n+i;
		upd(last[x],1);
	}
	for(int i=1; i<=n ;i++){
		int x=i;
		ll tmp=qry(last[x],1);
		mx[x]=max(mx[x],n-tmp+1);
		cout << mn[x] << ' ' << mx[x] << '\n';
	}
}