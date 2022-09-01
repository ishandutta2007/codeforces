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
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(1LL*k*(k-1) < n){
		puts("NO"); return 0;
	}
	puts("YES");
	vector<P>vec;
	vec.pb(mp(1,2));
	vec.pb(mp(2,1));
	vec.pb(mp(1,3));
	vec.pb(mp(3,1));
	vec.pb(mp(2,3));
	vec.pb(mp(3,2));
	int mx = 4;
	int cur = 1;
	while(vec.size() < n){
		vec.pb(mp(cur,mx));
		if(vec.size() == n) break;
		vec.pb(mp(mx,cur));
		cur++;
		if(cur == mx){
			cur = 1;
			mx++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",vec[i].fi,vec[i].sc);
	}
}