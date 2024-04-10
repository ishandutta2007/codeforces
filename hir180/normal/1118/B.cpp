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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
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
int n;
ll a[200005];
ll rui[200005],rui2[200005];
int main(){
	cin>>n;
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n){
		rui[i+1] = rui[i];
		if(i%2 == 0) rui[i+1] += a[i];
		else rui[i+1] -= a[i];
	}
	for(int i=n-1;i>=0;i--){
		rui2[i] = rui2[i+1];
		if(i%2 == 0) rui2[i] -= a[i];
		else rui2[i] += a[i];
	}
	ll ans = 0;
	rep(i,n){
		ll x = rui[i];
		ll y = rui2[i+1];
		if(x+y==0){ans++;}
	}
	cout << ans << endl;
}