#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
int a[400005];
int val[400005];
int ans[2][200005];


void make_left(int beg,int en){
	stack<P>S;
	int cur = 0;
	for(int i=beg-1;i>=en;i--){
		int nw = 0;
		while(!S.empty() && S.top().fi > a[i]){
			nw = max(nw+1, S.top().sc+1);
			S.pop();
		}
		S.push(mp(a[i],nw));
		cur = max(cur,(int)S.size()+nw);
		ans[0][a[i]] = cur;
	}
}
void make_right(int beg,int en){
	stack<P>S;
	int cur = 0;
	for(int i=beg+1;i<=en;i++){
		int nw = 0;
		while(!S.empty() && S.top().fi > a[i]){
			nw = max(nw+1, S.top().sc+1);
			S.pop();
		}
		S.push(mp(a[i],nw));
		cur = max(cur,(int)S.size()+nw);
		ans[1][a[i]] = cur;
	}
}
int main(){
	scanf("%d",&n);
	repn(i,n) scanf("%d",&a[i]);
	repn(i,n) a[n+i] = a[i];
	
	int pos = 0;
	repn(i,n) if(a[i] == 1) pos = i;
	
	//left
	make_left(pos+n,pos+1);
	//right
	make_right(pos,pos+n-1);
	
	P res = mp(INF,INF);
	for(int i=1;i<=n;i++){
		int L = ans[0][a[i]];
		int R = ans[1][a[i+n-1]];
		
		res = min(res,mp(max(L,R),i-1));
		
		//cout << L << " " << R << endl;
	}
	
	cout << ++res.fi << " " << res.sc << endl;
}