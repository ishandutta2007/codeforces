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
int n;
ll x[100005],y[100005];
bool m[100005];
int p[100005];
ll check(ll x,ll y){
	return x*x+y*y<=1500000LL*1500000LL;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		p[i] = i;
	}
	if(n==1){
		puts("1");
		return 0;
	}
	else if(n==2){
		if((x[2]+x[1])*(x[2]+x[1])+(y[2]+y[1])*(y[2]+y[1]) <= 1500000LL*1500000LL){
			puts("1 1");
		}
		else{
			puts("1 -1");
		}
		return 0;
	}
	while(1){
		ll cx,cy;
		int nxt;
		memset(m,0,sizeof(m));
		if(n%2 == 1){
			cx = x[p[1]]; cy = y[p[1]];
			nxt = 2;
		}
		else{
			if((x[p[2]]+x[p[1]])*(x[p[2]]+x[p[1]])+(y[p[2]]+y[p[1]])*(y[p[2]]+y[p[1]]) <= 1500000LL*1500000LL){
				cx = x[p[2]]+x[p[1]];
				cy = y[p[2]]+y[p[1]];
			}
			else{
				cx = x[p[1]]-x[p[2]];
				cy = y[p[1]]-y[p[2]];
				m[p[2]] = 1;
			}
			nxt = 3;
		}
		while(nxt<=n){
			if(check(cx+x[p[nxt]]+x[p[nxt+1]],cy+y[p[nxt]]+y[p[nxt+1]])){
				cx = cx+x[p[nxt]]+x[p[nxt+1]];
				cy = cy+y[p[nxt]]+y[p[nxt+1]];
			}
			else if(check(cx+x[p[nxt]]-x[p[nxt+1]],cy+y[p[nxt]]-y[p[nxt+1]])){
				cx = cx+x[p[nxt]]-x[p[nxt+1]];
				cy = cy+y[p[nxt]]-y[p[nxt+1]];
				m[p[nxt+1]] = 1;
			}
			else if(check(cx-x[p[nxt]]+x[p[nxt+1]],cy-y[p[nxt]]+y[p[nxt+1]])){
				cx = cx-x[p[nxt]]+x[p[nxt+1]];
				cy = cy-y[p[nxt]]+y[p[nxt+1]];
				m[p[nxt]] = 1;
			}
			else{
				cx = cx-x[p[nxt]]-x[p[nxt+1]];
				cy = cy-y[p[nxt]]-y[p[nxt+1]];
				m[p[nxt]] = m[p[nxt+1]] = 1;
			}
			nxt+=2;
		}
		if(!check(cx,cy)){
			random_shuffle(p+1,p+n+1);
		}
		else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(m[i]) printf("-1 ");
		else printf("1 ");
	}
	puts("");
}