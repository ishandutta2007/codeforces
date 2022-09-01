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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[1005];
vector<P>cur,nxt;
bool bit[1005][1005];
bool cmp(const P&a,const P&b){
	return a.sc-a.fi > b.sc-b.fi;
}
int main(){
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	rep(i,n) scanf("%d",&a[i]);
	cur.pb(P(0,n));
	rep(i,n){
		int x = a[i];
		if(cur.size() == n+1){
			for(int j=0;j<x;j++) bit[i][j] = 1;
			continue;
		}
		nxt.clear();
		int sum = 0,a,b;
		for(int j=1;j<cur.size();j++){
			int a = cur[j].fi, b = cur[j].sc;
			sum += b-a+1;
			if(sum >= x){
				if(sum > x){
					int curr = 0;
					for(int k=1;k<j;k++) {
						nxt.pb(cur[k]); curr += cur[k].sc-cur[k].fi+1;
						for(int a=cur[k].fi;a<=cur[k].sc;a++) bit[i][a] = 1;
					}
					assert(curr < x);
					nxt.pb(P(a,a+x-curr-1));
					for(int k=a;k<a+x-curr;k++) bit[i][k] = 1;
					nxt.pb(P(a+x-curr,b));
					nxt.pb(cur[0]);
					for(int k=j+1;k<cur.size();k++) nxt.pb(cur[k]);
				}
				else if(cur[0].sc-cur[0].fi > cur[j].sc-cur[j].fi){
					int curr = 0;
					for(int k=1;k<j;k++) {
						nxt.pb(cur[k]); curr += cur[k].sc-cur[k].fi+1;
						for(int a=cur[k].fi;a<=cur[k].sc;a++) bit[i][a] = 1;
					}
					assert(curr < x);
					nxt.pb(P(cur[0].fi,cur[0].fi+x-curr-1));
					for(int k=cur[0].fi;k<cur[0].fi+x-curr;k++) bit[i][k] = 1;
					nxt.pb(P(cur[0].fi+x-curr,cur[0].sc));
					nxt.pb(cur[j]);
					for(int k=j+1;k<cur.size();k++) nxt.pb(cur[k]);
				}
				else{
				    assert(cur[0].sc-cur[0].fi == cur[j].sc-cur[j].fi && cur[j].sc != cur[j].fi);
					int curr = 0;
					for(int k=1;k<j;k++) {
						nxt.pb(cur[k]); curr += cur[k].sc-cur[k].fi+1;
						for(int a=cur[k].fi;a<=cur[k].sc;a++) bit[i][a] = 1;
					}
					nxt.pb(P(cur[0].fi,cur[0].fi)); bit[i][cur[0].fi] = 1;
					nxt.pb(P(cur[0].fi+1,cur[0].sc));
					nxt.pb(P(cur[j].fi,cur[j].sc-1));for(int w=cur[j].fi;w<cur[j].sc;w++) bit[i][w] = 1;
					nxt.pb(P(cur[j].sc,cur[j].sc));
					for(int k=j+1;k<cur.size();k++) nxt.pb(cur[k]);
				}
				goto nxty;
			}
		}
		rep(j,cur.size()) if(j){
			nxt.pb(cur[j]);
			for(int a=cur[j].fi;a<=cur[j].sc;a++) bit[i][a] = 1;
		}
		a = cur[0].fi, b = cur[0].sc;
		nxt.pb(P(a,a+x-sum-1));
		for(int q=a;q<a+x-sum;q++) bit[i][q] = 1;
		nxt.pb(P(a+x-sum,b));
		nxty:;
		
		sort(nxt.begin(),nxt.end(),cmp);
		int L = 0;
		rep(i,nxt.size()) L += nxt[i].sc-nxt[i].fi+1;
		assert(L == n+1);
	    //rep(i,nxt.size()) cout << nxt[i].fi << " " << nxt[i].sc << endl;
	    //cout << "+______" << endl;
		cur = nxt;
	}
	assert(cur.size() == n+1);
	rep(i,n){
	   int C = 0;
	   rep(j,n+1) C += bit[i][j];
	   assert(C == a[i]);
	}
	vector<ll>vec;
	for(int i=0;i<=n;i++){
	   ll cur = 0;
	   rep(j,n) cur = (cur*2LL+(ll)(bit[j][i]))%mod;
	   vec.pb(cur);
	}
	sort(vec.begin(),vec.end());
	//for(int i=0;i<vec.size();i++) cout << vec[i] << endl;
	for(int i=1;i<vec.size();i++) assert(vec[i-1] != vec[i]);
	printf("%d\n",n+1);
	for(int i=0;i<=n;i++){
		rep(j,n){
			if(bit[j][i]) printf("1");
			else printf("0");
		}
		puts("");
	}
	return 0;
}