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
ll k;
int main(){
	cin>>k;
	for(int a=1997;a>=3;a-=2){
		ll rem = k%a;
		ll remm = a-rem;
		ll y = (600000LL/a*a) + remm;
		ll sum = y+k;
		assert(sum%a == 0);
		ll x = sum/a+a/2;
		if(y < x) continue;
		if(1LL*(x-(a-1)/2)*a < 1LL*(x-(a-3)/2)*(a-2)) continue;
		cout<<a+2<<endl;
		cout<<y<<" "<<-999999LL<<" ";
		for(int i=0;i<(a-1)/2;i++){
			cout<<x<<" "<<-x-1<<" ";
		}
		cout<<x<<endl;
		assert(1LL*(x-(a-1)/2)*a-y == k);
		return 0;
	}
	puts("-1");
}