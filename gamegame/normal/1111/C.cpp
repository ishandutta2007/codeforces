#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll x,y;
int a[100002];
ll solve(int l,int r){
	ll res;
	int tmp=lower_bound(a+1,a+k+1,r+1)-lower_bound(a+1,a+k+1,l);
	if(tmp==0) res=x;
	else{
		res=y*tmp*(r-l+1);
		if(l!=r){
			int m=(l+r)/2;
			res=min(res,solve(l,m)+solve(m+1,r));
		}
	}
	return res;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> x >> y;
	for(int i=1; i<=k ;i++) cin >> a[i];
	sort(a+1,a+k+1);
	a[k+1]=2e9;//sdasd
	cout << solve(1,(1<<n)) << endl;
}