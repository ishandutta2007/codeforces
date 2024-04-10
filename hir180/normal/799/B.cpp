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
int n,q,p[200005],a[200005],b[200005];
multiset<P>ts[4];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&p[i]);
	}
	repn(i,n){
		scanf("%d",&a[i]);
		ts[a[i]].insert(mp(p[i],i));
	}
	repn(i,n){
		scanf("%d",&b[i]);
		ts[b[i]].insert(mp(p[i],i));
	}
	scanf("%d",&q);
	repn(i,q){
		int aa;
		scanf("%d",&aa);
		if(ts[aa].empty()){
			printf("-1 ");
		}
		else{
			P pp = *ts[aa].begin();
			printf("%d ",pp.fi);
			int num = pp.sc;
			ts[a[num]].erase(ts[a[num]].find(mp(p[num],num)));
			ts[b[num]].erase(ts[b[num]].find(mp(p[num],num)));
		}
	}
	puts("");
}