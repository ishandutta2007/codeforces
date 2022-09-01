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
int n,k,a[300005],ans[300005];
priority_queue<P>que;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) que.push(mp(a[i],i));
	int nxt = k+1;
	for(int i=1;i<=n;i++){
		if(nxt <= n){
			que.push(mp(a[nxt],nxt));
			nxt++;
		}
		ans[que.top().sc] = k+i;
		que.pop();
	}
	ll A = 0;
	for(int i=1;i<=n;i++) A += 1LL*(ans[i]-i)*a[i];
	printf("%lld\n",A);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}