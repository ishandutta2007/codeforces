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
int n,a,b;
vector<P>p,q;
int sol(vector<P>vec,int val){
	vector<int>mx;
	for(int i=0;i<vec.size();i++){
		if(i==0) mx.pb(vec[i].sc);
		else mx.pb(max(mx[i-1],vec[i].sc));
	}
	int ret = -INF;
	for(int i=1;i<vec.size();i++){
		int zan = val - vec[i].fi;
		int a = POSL(vec,mp(zan+1,-1));
		a--;
		if(a >= 0){
		    a = min(a,i-1);
			ret = max(ret,vec[i].sc+mx[a]);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	rep(i,n){
		int a,b; string s; cin>>a>>b>>s;
		if(s=="C"){
			p.pb(mp(b,a));
		}
		else{
			q.pb(mp(b,a));
		}
	}
	SORT(p); SORT(q);
	int vp = -INF,vq = -INF;
	for(int i=0;i<p.size();i++){
		if(p[i].fi <= a) vp = max(vp,p[i].sc);
	}
	for(int i=0;i<q.size();i++){
		if(q[i].fi <= b) vq = max(vq,q[i].sc);
	}
	int ans = -INF;
	if(vp>=0&&vq>=0) ans=vp+vq;
	ans = max(ans,sol(p,a));
	ans = max(ans,sol(q,b));
	if(ans<0) cout<<0<<endl;
	else cout<<ans<<endl;
}