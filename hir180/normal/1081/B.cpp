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
vector<int>num[100005];
int n,col[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		num[n-a].pb(i);
	}
	int nw = 1;
	for(int i=1;i<=n;i++){
		int sz = num[i].size();
		if(sz%i != 0){
			puts("Impossible"); return 0;
		}
		for(int x=0;x<sz;x++){
			col[num[i][x]] = nw+x%(sz/i);
		}
		nw += sz/i;
	}
	puts("Possible");
	for(int i=1;i<=n;i++) printf("%d\n",col[i]);
}