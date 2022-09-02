//B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n; ll x,y;
int a[500005];
bool u[2000005];
vector<int>val;
vector<ll>rui;
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		val.pb(a[i]);
	}
	SORT(val);
	for(int i=0;i<n;i++){
		if(i==0) rui.pb(val[i]*1LL);
		else rui.pb(rui[i-1]+val[i]*1LL);
	}
	ll L = x/y;
	ll ans = 1e18;
	for(int i=2;i<=2000000;i++){
		if(u[i]) continue;
		ll ret = 0;
		for(int j=i;j<=2000000;j+=i){
			u[j] = 1;
			int z = POSU(val,j-i);
			int xx = POSU(val,j-min(L+1,1LL*i));
			int yy = POSU(val,j);
			//cout<<z<<xx<<yy<<endl;
			//[xx,yy)...add
			//[z,xx)...erase
			ll hoge = (yy?rui[yy-1]:0LL)-(xx?rui[xx-1]:0LL);
			ll UP = 1LL*(yy-xx)*j;
			ret += (UP-hoge)*1LL*y + 1LL*(xx-z)*x;
			//if(i==2)cout<<z<<xx<<yy<<endl;
		}
		ans = min(ans,ret); 
	}
	cout<<ans<<endl;
}