#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll h;
ll a[200001];
pair<ll,int>b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> h;
	if(n==2){
		cout << 0 << endl;
		cout << "2 2" << endl;
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]={a[i],i};
	}
	sort(b+1,b+n+1);
	ll mn1=min(b[2].fi+b[3].fi,b[1].fi+b[2].fi+h);
	ll mx1=max(b[1].fi+b[n].fi+h,b[n-1].fi+b[n].fi);
	ll mn2=b[1].fi+b[2].fi;
	ll mx2=b[n-1].fi+b[n].fi;
	if(mx1-mn1>mx2-mn2){
		cout << mx2-mn2 << '\n';
		for(int i=1; i<=n ;i++) cout << 2 << ' ';
		cout << endl;
	}
	else{
		cout << mx1-mn1 << '\n';
		for(int i=1; i<=n ;i++) cout << 2-(i==b[1].se) << ' ';
		cout << endl;
	}
}