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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[100005];
int main(){
	scanf("%d",&n);
	repn(i,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int lb = 0,ub = n+1;
	while(ub-lb>1){
		int mid = (lb+ub)/2;
		for(int i=1;i<=mid;i++){
			if(a[i] == a[n+i-mid]){
				goto fail;
			}
		}
		lb = mid; continue;
		fail:; ub = mid;
	}
	cout<<lb<<endl;
}