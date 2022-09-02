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
int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x = (a+c-1)/c * b;
	ll lb = 0,ub = 1e9;
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		if(mid < d) lb = mid;
		ll cnt = (mid/b)*c + ((mid-d)/b)*c;
		if(cnt >= a) ub = mid;
		else lb = mid;
	}
	if(ub<x) puts("YES");
	else puts("NO");
}