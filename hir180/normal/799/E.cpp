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
int n,m,k,a[200005],p,q;
int t[200005];
int aa[4];
ll sum3[200005],sum2[200005];
vector<P>vec[4];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(m<k){puts("-1"); return 0;}
	repn(i,n) scanf("%d",&a[i]);
	scanf("%d",&p);
	repn(i,p){
		int x; scanf("%d",&x);
		t[x] |= 1;
	}
	scanf("%d",&q);
	repn(i,q){
		int x; scanf("%d",&x);
		t[x] |= 2;
	}
	repn(i,n){
		aa[t[i]]++;
		vec[t[i]].pb(mp(a[i],i));
	}
	rep(i,4) sort(vec[i].begin(),vec[i].end());
	int L=INF,R=-INF;
	for(int x=0;x<=m;x++){
		if(aa[3]>=x && aa[1]>=k-x && aa[2]>=k-x && m>=x+2*max(0,k-x) && m<=n-(aa[3]-x)){
			L = min(L,x);
			R = max(R,x);
		}
	}
	if(L > R){
		puts("-1");
		return 0;
	}
	ll sum = 0;
	for(int x=1;x<=aa[3];x++){
		sum += vec[3][x-1].fi;
		sum3[x] = sum;
	}
	sum = 0;
	for(int x=1;x<=min(vec[1].size(),vec[2].size());x++){
		sum += vec[1][x-1].fi+vec[2][x-1].fi;
		sum2[x] = sum;
	}
	multiset<P>use,unuse;
	ll S = 0;
	for(int i=max(0,k-L);i<vec[1].size();i++){
		use.insert(vec[1][i]);
		S += vec[1][i].fi;
	}
	for(int i=max(0,k-L);i<vec[2].size();i++){
		use.insert(vec[2][i]);
		S += vec[2][i].fi;
	}
	for(int i=0;i<vec[0].size();i++){
		use.insert(vec[0][i]);
		S += vec[0][i].fi;
	}
	while(use.size() > m-L-2*max(0,k-L)){
	    multiset<P>::iterator it=use.end();
	    it--;
		P p = *it;
		use.erase(it);
		S -= p.fi;
		unuse.insert(p);
	}
	assert(use.size() == m-L-2*max(0,k-L));
	ll ans = sum3[L]+sum2[max(0,k-L)]+S;
	for(int i=L+1;i<=R;i++){
		int id = k-i;
		if(unuse.size()){
			multiset<P>::iterator it=unuse.begin();
			P p = *it;
			S += p.fi;
			use.insert(p);
			unuse.erase(it);
		}
		if(unuse.size()){
			multiset<P>::iterator it=unuse.begin();
			P p = *it;
			S += p.fi;
			use.insert(p);
			unuse.erase(it);
		}
		if(id>=0) {use.insert(vec[1][id]);S+=vec[1][id].fi;}
		if(id>=0) {use.insert(vec[2][id]);S+=vec[2][id].fi;}
		while(use.size() > m-i-2*max(0,k-i)){
			multiset<P>::iterator it=use.end();
    	    it--;
    		P p = *it;
    		use.erase(it);
    		S -= p.fi;
    		unuse.insert(p);
		}
		assert(use.size() ==  m-i-2*max(0,k-i)) ;
		ans = min(ans,sum3[i]+sum2[max(0,k-i)]+S);
		//assert(k>=i);
	}
	cout << ans << endl;
}