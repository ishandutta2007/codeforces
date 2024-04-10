#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n,m;
vector<ll>c[5005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		int a; ll cc;
		scanf("%d%lld",&a,&cc);
		c[a].pb(cc);
	}
	rep(i,5005) SORT(c[i]);
	ll ans = 1e18;
	for(int ch=0;ch<=n-c[1].size();ch++){
		int has = c[1].size()+ch;
		if(has == 0) continue;
		int need = ch;
		ll val = 0;
		priority_queue<int,vector<int>,greater<int> >que;
		for(int i=2;i<=m;i++){
			if(1){
				int sz = c[i].size();
				int cur = 0;
				while(has <= sz){
					val += c[i][cur];
					sz--;
					cur++;
					need--;
				}
				while(sz){
					que.push(c[i][cur]);
					cur++;
					sz--;
				}
			}
		}
		while(need > 0 && que.size()){
			val += que.top();
			que.pop();
			need--;
		}
		if(need <= 0) ans = min(ans,val);
	}
	cout<<ans<<endl;
}