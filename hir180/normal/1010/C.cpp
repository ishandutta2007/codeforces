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
int n,k,a[100005];
int main(){
	scanf("%d%d",&n,&k);
	int cur = k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int B = a[i]%k;
		if(B == 0) B = k;
		cur=__gcd(cur,B);
	}
	vector<int>ans;
	for(int i=0;i<k;i++){
		if(__gcd(k,i)%cur == 0) ans.pb(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	puts("");
}