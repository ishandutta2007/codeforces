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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int a[200005],pos[200005],n;
ll rui[200005];
ll ret;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); rui[i] = rui[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&pos[i]);
	}
	set<P>S;
	S.insert(mp(1,n));
	multiset<ll>M;
	M.insert(rui[n]);
	
	for(int i=1;i<=n;i++){
		set<P>::iterator it = S.upper_bound(mp(pos[i],INF));
		it--;
		int L = (*it).fi, R = (*it).sc;
		S.erase(it);
		M.erase(M.find(rui[R]-rui[L-1]));
		
		if(L < pos[i]){
			S.insert(mp(L,pos[i]-1));
			M.insert(rui[pos[i]-1] - rui[L-1]);
		}
		if(R > pos[i]){
			S.insert(mp(pos[i]+1,R));
			M.insert(rui[R] - rui[pos[i]]);
		}
		if(i==n){
			puts("0");return 0;
		}
		multiset<ll>::iterator it2 = M.end(); --it2;
		printf("%lld\n",(*it2));
	}
}