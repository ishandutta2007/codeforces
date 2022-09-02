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
int main(){
	cin>>n;
	rep(i,n){
		ll x; cin>>x;
		ll ans = -1e18;
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				ll y = 1LL*a*6+1LL*b*9;
				if((x-y)<0 || (x-y)%4 != 0) continue;
				ans = max(ans,1LL*(a+b)+(x-y)/4);
			}
		}
		cout<<(ans<0?-1:ans)<<endl;
	}
}