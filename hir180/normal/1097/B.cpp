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
int n,a[15];
int main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	bool ok = 0;
	rep(m,(1<<n)){
		int x = 0;
		rep(j,n){
			if(((m>>j)&1)) x += a[j];
			else x -= a[j];
		}
		x = (x%360+360)%360;
		if(x == 0){
			ok = 1;
			break;
		}
	}
	puts(ok?"YES":"NO");
}