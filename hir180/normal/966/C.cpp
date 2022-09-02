#include <bits/stdc++.h>
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
int n;
ll a[100005];
int cur[65];
vector<ll>ans;
queue<ll>hoge[65];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		int fin = -1;
		for(int ii=0;ii<64;ii++){
			if(((a[i]>>ii)&1LL)){
				cur[ii]++;
				fin = ii;
			}
		}
		hoge[fin].push(a[i]);
	}
	while(ans.size() != n){
		ll nxt = -1;
		for(int ii=0;ii<64;ii++){
			if(cur[ii]%2 == 1){
				if(hoge[ii].empty()) continue;
				nxt = hoge[ii].front(); hoge[ii].pop();
				for(int j=0;j<64;j++){
					if(((nxt>>j)&1LL)){
						cur[j]--;
					}
				}
				break;
			}
		}
		
		if(nxt == -1){
			puts("No"); return 0;
		}
		ans.pb(nxt);
	}
	puts("Yes");
	for(int i=n-1;i>=0;i--) printf("%lld ",ans[i]);
	puts("");
}