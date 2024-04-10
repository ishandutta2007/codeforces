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
ll cur[100005];
int n,m; ll L,a[100005];
int ans;
int main(){
	scanf("%d%d%lld",&n,&m,&L);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
//	init();
	for(int i=1;i<=n;i++){
		if(a[i] > L) ans++;
		if(i>1 && a[i-1] > L && a[i] > L) ans--;
	}
	rep(i,m){
		int ty; scanf("%d",&ty);
		if(ty == 0){
			printf("%d\n",ans);
		}
		else{
			int pos; ll num; scanf("%d%lld",&pos,&num);
			if(pos-1>=1 && a[pos-1]>L && a[pos]>L) ans++;
			if(pos+1<=n && a[pos+1]>L && a[pos]>L) ans++;
			if(a[pos]>L) ans--;
			
			a[pos]+=num;
			
			if(pos-1>=1 && a[pos-1]>L && a[pos]>L) ans--;
			if(pos+1<=n && a[pos+1]>L && a[pos]>L) ans--;
			if(a[pos]>L) ans++;
		}
	}
}